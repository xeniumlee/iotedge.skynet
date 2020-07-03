#!/bin/sh
set -e

RELEASE_DIR=release
mkdir -p ${RELEASE_DIR}
LUAC=skynet/3rd/lua/luac

PLAT=$1
REPO=$2

upload() {
    if [ -n "${REPO}" ]; then
        local DIR=$1
        local TARBALL=$2
        local TARGET=${REPO}/${PLAT}/${DIR}
        ssh -oStrictHostKeyChecking=no ${REPO%:*} "mkdir -p ${REPO#*:}/${PLAT}/${DIR}"
        scp -oStrictHostKeyChecking=no -q ${TARBALL} ${TARGET}/
        echo "${TARBALL} uploaded to ${TARGET}"
        rm -f ${TARBALL}
    fi
}

compile() {
    for DIR in $@; do
        for FD in ${DIR}/*; do
            if [ -d ${FD} ]; then
                compile ${FD}
            else
                if [ ${FD##*.} = "lua" ]; then
                    ${LUAC} -o ${FD%.lua}.luac ${FD}
                fi
            fi
        done
    done
}

if [ -n "${PLAT}" ]; then
    if [ ${PLAT} = "arm_v7" ] || [ ${PLAT} = "x86_64" ]; then
        REV=$(git rev-parse HEAD | cut -c1-5)
        INFO=PLATFORM
        echo -n ${REV}-${PLAT} > ${INFO}

        LUADIRS="lualib skynet/lualib service skynet/service sys"
        compile ${LUADIRS}

        TARBALL=${RELEASE_DIR}/${REV}.tar.gz
        DIRS="${INFO} bin config.* scripts iotedge.config.prod"

        tar --transform="s|bin/skynet$|bin/iotedge|" \
            --transform="s|^|iotedge-${REV}/|" \
            --exclude=gate.so \
            --exclude=sproto.so \
            --exclude=client.so \
            --exclude=lib* \
            --exclude=*.lua \
            -czf ${TARBALL} ${DIRS} ${LUADIRS}
        find . -name "*.luac" |xargs rm -f
        rm -f ${INFO}

        echo "${TARBALL} created"
        upload core ${TARBALL}

        for APP in app/*; do
            BASE=$(basename ${APP})
            compile ${APP}

            TARBALL=${RELEASE_DIR}/v_${BASE#*_v_}.tar.gz
            tar --exclude=*.lua -czf ${TARBALL} ${APP}
            find . -name "*.luac" |xargs rm -f

            echo "${TARBALL} created"
            upload ${BASE%_v_*} ${TARBALL}
        done
    else
        echo "$0 x86_64/arm_v7 repo"
    fi
else
    echo "$0 x86_64/arm_v7 repo"
fi
