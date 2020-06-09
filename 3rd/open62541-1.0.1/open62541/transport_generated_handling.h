/* Generated from Opc.Ua.Types.bsd, Custom.Opc.Ua.Transport.bsd with script /root/open62541/tools/generate_datatypes.py
 * on host jayli by user root at 2020-06-08 04:40:25 */

#ifndef TRANSPORT_GENERATED_HANDLING_H_
#define TRANSPORT_GENERATED_HANDLING_H_

#include "transport_generated.h"

_UA_BEGIN_DECLS

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wmissing-field-initializers"
# pragma GCC diagnostic ignored "-Wmissing-braces"
#endif


/* MessageType */
static UA_INLINE void
UA_MessageType_init(UA_MessageType *p) {
    memset(p, 0, sizeof(UA_MessageType));
}

static UA_INLINE UA_MessageType *
UA_MessageType_new(void) {
    return (UA_MessageType*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_MESSAGETYPE]);
}

static UA_INLINE UA_StatusCode
UA_MessageType_copy(const UA_MessageType *src, UA_MessageType *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_MessageType_deleteMembers(UA_MessageType *p) {
    memset(p, 0, sizeof(UA_MessageType));
}

static UA_INLINE void
UA_MessageType_clear(UA_MessageType *p) {
    memset(p, 0, sizeof(UA_MessageType));
}

static UA_INLINE void
UA_MessageType_delete(UA_MessageType *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_MESSAGETYPE]);
}

/* ChunkType */
static UA_INLINE void
UA_ChunkType_init(UA_ChunkType *p) {
    memset(p, 0, sizeof(UA_ChunkType));
}

static UA_INLINE UA_ChunkType *
UA_ChunkType_new(void) {
    return (UA_ChunkType*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_CHUNKTYPE]);
}

static UA_INLINE UA_StatusCode
UA_ChunkType_copy(const UA_ChunkType *src, UA_ChunkType *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_ChunkType_deleteMembers(UA_ChunkType *p) {
    memset(p, 0, sizeof(UA_ChunkType));
}

static UA_INLINE void
UA_ChunkType_clear(UA_ChunkType *p) {
    memset(p, 0, sizeof(UA_ChunkType));
}

static UA_INLINE void
UA_ChunkType_delete(UA_ChunkType *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_CHUNKTYPE]);
}

/* TcpMessageHeader */
static UA_INLINE void
UA_TcpMessageHeader_init(UA_TcpMessageHeader *p) {
    memset(p, 0, sizeof(UA_TcpMessageHeader));
}

static UA_INLINE UA_TcpMessageHeader *
UA_TcpMessageHeader_new(void) {
    return (UA_TcpMessageHeader*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_TCPMESSAGEHEADER]);
}

static UA_INLINE UA_StatusCode
UA_TcpMessageHeader_copy(const UA_TcpMessageHeader *src, UA_TcpMessageHeader *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_TcpMessageHeader_deleteMembers(UA_TcpMessageHeader *p) {
    memset(p, 0, sizeof(UA_TcpMessageHeader));
}

static UA_INLINE void
UA_TcpMessageHeader_clear(UA_TcpMessageHeader *p) {
    memset(p, 0, sizeof(UA_TcpMessageHeader));
}

static UA_INLINE void
UA_TcpMessageHeader_delete(UA_TcpMessageHeader *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_TCPMESSAGEHEADER]);
}

/* TcpHelloMessage */
static UA_INLINE void
UA_TcpHelloMessage_init(UA_TcpHelloMessage *p) {
    memset(p, 0, sizeof(UA_TcpHelloMessage));
}

static UA_INLINE UA_TcpHelloMessage *
UA_TcpHelloMessage_new(void) {
    return (UA_TcpHelloMessage*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}

static UA_INLINE UA_StatusCode
UA_TcpHelloMessage_copy(const UA_TcpHelloMessage *src, UA_TcpHelloMessage *dst) {
    return UA_copy(src, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}

static UA_INLINE void
UA_TcpHelloMessage_deleteMembers(UA_TcpHelloMessage *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}

static UA_INLINE void
UA_TcpHelloMessage_clear(UA_TcpHelloMessage *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}

static UA_INLINE void
UA_TcpHelloMessage_delete(UA_TcpHelloMessage *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}

/* TcpAcknowledgeMessage */
static UA_INLINE void
UA_TcpAcknowledgeMessage_init(UA_TcpAcknowledgeMessage *p) {
    memset(p, 0, sizeof(UA_TcpAcknowledgeMessage));
}

static UA_INLINE UA_TcpAcknowledgeMessage *
UA_TcpAcknowledgeMessage_new(void) {
    return (UA_TcpAcknowledgeMessage*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE]);
}

static UA_INLINE UA_StatusCode
UA_TcpAcknowledgeMessage_copy(const UA_TcpAcknowledgeMessage *src, UA_TcpAcknowledgeMessage *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_TcpAcknowledgeMessage_deleteMembers(UA_TcpAcknowledgeMessage *p) {
    memset(p, 0, sizeof(UA_TcpAcknowledgeMessage));
}

static UA_INLINE void
UA_TcpAcknowledgeMessage_clear(UA_TcpAcknowledgeMessage *p) {
    memset(p, 0, sizeof(UA_TcpAcknowledgeMessage));
}

static UA_INLINE void
UA_TcpAcknowledgeMessage_delete(UA_TcpAcknowledgeMessage *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE]);
}

/* TcpErrorMessage */
static UA_INLINE void
UA_TcpErrorMessage_init(UA_TcpErrorMessage *p) {
    memset(p, 0, sizeof(UA_TcpErrorMessage));
}

static UA_INLINE UA_TcpErrorMessage *
UA_TcpErrorMessage_new(void) {
    return (UA_TcpErrorMessage*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}

static UA_INLINE UA_StatusCode
UA_TcpErrorMessage_copy(const UA_TcpErrorMessage *src, UA_TcpErrorMessage *dst) {
    return UA_copy(src, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}

static UA_INLINE void
UA_TcpErrorMessage_deleteMembers(UA_TcpErrorMessage *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}

static UA_INLINE void
UA_TcpErrorMessage_clear(UA_TcpErrorMessage *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}

static UA_INLINE void
UA_TcpErrorMessage_delete(UA_TcpErrorMessage *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}

/* SecureConversationMessageHeader */
static UA_INLINE void
UA_SecureConversationMessageHeader_init(UA_SecureConversationMessageHeader *p) {
    memset(p, 0, sizeof(UA_SecureConversationMessageHeader));
}

static UA_INLINE UA_SecureConversationMessageHeader *
UA_SecureConversationMessageHeader_new(void) {
    return (UA_SecureConversationMessageHeader*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEHEADER]);
}

static UA_INLINE UA_StatusCode
UA_SecureConversationMessageHeader_copy(const UA_SecureConversationMessageHeader *src, UA_SecureConversationMessageHeader *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_SecureConversationMessageHeader_deleteMembers(UA_SecureConversationMessageHeader *p) {
    memset(p, 0, sizeof(UA_SecureConversationMessageHeader));
}

static UA_INLINE void
UA_SecureConversationMessageHeader_clear(UA_SecureConversationMessageHeader *p) {
    memset(p, 0, sizeof(UA_SecureConversationMessageHeader));
}

static UA_INLINE void
UA_SecureConversationMessageHeader_delete(UA_SecureConversationMessageHeader *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEHEADER]);
}

/* AsymmetricAlgorithmSecurityHeader */
static UA_INLINE void
UA_AsymmetricAlgorithmSecurityHeader_init(UA_AsymmetricAlgorithmSecurityHeader *p) {
    memset(p, 0, sizeof(UA_AsymmetricAlgorithmSecurityHeader));
}

static UA_INLINE UA_AsymmetricAlgorithmSecurityHeader *
UA_AsymmetricAlgorithmSecurityHeader_new(void) {
    return (UA_AsymmetricAlgorithmSecurityHeader*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}

static UA_INLINE UA_StatusCode
UA_AsymmetricAlgorithmSecurityHeader_copy(const UA_AsymmetricAlgorithmSecurityHeader *src, UA_AsymmetricAlgorithmSecurityHeader *dst) {
    return UA_copy(src, dst, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}

static UA_INLINE void
UA_AsymmetricAlgorithmSecurityHeader_deleteMembers(UA_AsymmetricAlgorithmSecurityHeader *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}

static UA_INLINE void
UA_AsymmetricAlgorithmSecurityHeader_clear(UA_AsymmetricAlgorithmSecurityHeader *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}

static UA_INLINE void
UA_AsymmetricAlgorithmSecurityHeader_delete(UA_AsymmetricAlgorithmSecurityHeader *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}

/* SymmetricAlgorithmSecurityHeader */
static UA_INLINE void
UA_SymmetricAlgorithmSecurityHeader_init(UA_SymmetricAlgorithmSecurityHeader *p) {
    memset(p, 0, sizeof(UA_SymmetricAlgorithmSecurityHeader));
}

static UA_INLINE UA_SymmetricAlgorithmSecurityHeader *
UA_SymmetricAlgorithmSecurityHeader_new(void) {
    return (UA_SymmetricAlgorithmSecurityHeader*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_SYMMETRICALGORITHMSECURITYHEADER]);
}

static UA_INLINE UA_StatusCode
UA_SymmetricAlgorithmSecurityHeader_copy(const UA_SymmetricAlgorithmSecurityHeader *src, UA_SymmetricAlgorithmSecurityHeader *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_SymmetricAlgorithmSecurityHeader_deleteMembers(UA_SymmetricAlgorithmSecurityHeader *p) {
    memset(p, 0, sizeof(UA_SymmetricAlgorithmSecurityHeader));
}

static UA_INLINE void
UA_SymmetricAlgorithmSecurityHeader_clear(UA_SymmetricAlgorithmSecurityHeader *p) {
    memset(p, 0, sizeof(UA_SymmetricAlgorithmSecurityHeader));
}

static UA_INLINE void
UA_SymmetricAlgorithmSecurityHeader_delete(UA_SymmetricAlgorithmSecurityHeader *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_SYMMETRICALGORITHMSECURITYHEADER]);
}

/* SequenceHeader */
static UA_INLINE void
UA_SequenceHeader_init(UA_SequenceHeader *p) {
    memset(p, 0, sizeof(UA_SequenceHeader));
}

static UA_INLINE UA_SequenceHeader *
UA_SequenceHeader_new(void) {
    return (UA_SequenceHeader*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_SEQUENCEHEADER]);
}

static UA_INLINE UA_StatusCode
UA_SequenceHeader_copy(const UA_SequenceHeader *src, UA_SequenceHeader *dst) {
    *dst = *src;
    return UA_STATUSCODE_GOOD;
}

static UA_INLINE void
UA_SequenceHeader_deleteMembers(UA_SequenceHeader *p) {
    memset(p, 0, sizeof(UA_SequenceHeader));
}

static UA_INLINE void
UA_SequenceHeader_clear(UA_SequenceHeader *p) {
    memset(p, 0, sizeof(UA_SequenceHeader));
}

static UA_INLINE void
UA_SequenceHeader_delete(UA_SequenceHeader *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_SEQUENCEHEADER]);
}

/* SecureConversationMessageFooter */
static UA_INLINE void
UA_SecureConversationMessageFooter_init(UA_SecureConversationMessageFooter *p) {
    memset(p, 0, sizeof(UA_SecureConversationMessageFooter));
}

static UA_INLINE UA_SecureConversationMessageFooter *
UA_SecureConversationMessageFooter_new(void) {
    return (UA_SecureConversationMessageFooter*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEFOOTER]);
}

static UA_INLINE UA_StatusCode
UA_SecureConversationMessageFooter_copy(const UA_SecureConversationMessageFooter *src, UA_SecureConversationMessageFooter *dst) {
    return UA_copy(src, dst, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEFOOTER]);
}

static UA_INLINE void
UA_SecureConversationMessageFooter_deleteMembers(UA_SecureConversationMessageFooter *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEFOOTER]);
}

static UA_INLINE void
UA_SecureConversationMessageFooter_clear(UA_SecureConversationMessageFooter *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEFOOTER]);
}

static UA_INLINE void
UA_SecureConversationMessageFooter_delete(UA_SecureConversationMessageFooter *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEFOOTER]);
}

/* SecureConversationMessageAbortBody */
static UA_INLINE void
UA_SecureConversationMessageAbortBody_init(UA_SecureConversationMessageAbortBody *p) {
    memset(p, 0, sizeof(UA_SecureConversationMessageAbortBody));
}

static UA_INLINE UA_SecureConversationMessageAbortBody *
UA_SecureConversationMessageAbortBody_new(void) {
    return (UA_SecureConversationMessageAbortBody*)UA_new(&UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEABORTBODY]);
}

static UA_INLINE UA_StatusCode
UA_SecureConversationMessageAbortBody_copy(const UA_SecureConversationMessageAbortBody *src, UA_SecureConversationMessageAbortBody *dst) {
    return UA_copy(src, dst, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEABORTBODY]);
}

static UA_INLINE void
UA_SecureConversationMessageAbortBody_deleteMembers(UA_SecureConversationMessageAbortBody *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEABORTBODY]);
}

static UA_INLINE void
UA_SecureConversationMessageAbortBody_clear(UA_SecureConversationMessageAbortBody *p) {
    UA_clear(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEABORTBODY]);
}

static UA_INLINE void
UA_SecureConversationMessageAbortBody_delete(UA_SecureConversationMessageAbortBody *p) {
    UA_delete(p, &UA_TRANSPORT[UA_TRANSPORT_SECURECONVERSATIONMESSAGEABORTBODY]);
}

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic pop
#endif

_UA_END_DECLS

#endif /* TRANSPORT_GENERATED_HANDLING_H_ */
