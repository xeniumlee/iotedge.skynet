/* Generated from Opc.Ua.Types.bsd, Custom.Opc.Ua.Transport.bsd with script /root/edge/open62541/tools/generate_datatypes.py
 * on host jayli by user root at 2020-06-17 04:03:31 */

#ifndef TRANSPORT_GENERATED_ENCODING_BINARY_H_
#define TRANSPORT_GENERATED_ENCODING_BINARY_H_

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else
# include "ua_types_encoding_binary.h"
# include "transport_generated.h"
#endif



/* MessageType */
static UA_INLINE size_t
UA_MessageType_calcSizeBinary(const UA_MessageType *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_MESSAGETYPE]);
}
static UA_INLINE UA_StatusCode
UA_MessageType_encodeBinary(const UA_MessageType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_MESSAGETYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MessageType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MessageType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_MESSAGETYPE], NULL);
}

/* ChunkType */
static UA_INLINE size_t
UA_ChunkType_calcSizeBinary(const UA_ChunkType *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_CHUNKTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ChunkType_encodeBinary(const UA_ChunkType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_CHUNKTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ChunkType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ChunkType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_CHUNKTYPE], NULL);
}

/* TcpMessageHeader */
static UA_INLINE size_t
UA_TcpMessageHeader_calcSizeBinary(const UA_TcpMessageHeader *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPMESSAGEHEADER]);
}
static UA_INLINE UA_StatusCode
UA_TcpMessageHeader_encodeBinary(const UA_TcpMessageHeader *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPMESSAGEHEADER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TcpMessageHeader_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TcpMessageHeader *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPMESSAGEHEADER], NULL);
}

/* TcpHelloMessage */
static UA_INLINE size_t
UA_TcpHelloMessage_calcSizeBinary(const UA_TcpHelloMessage *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE]);
}
static UA_INLINE UA_StatusCode
UA_TcpHelloMessage_encodeBinary(const UA_TcpHelloMessage *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TcpHelloMessage_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TcpHelloMessage *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPHELLOMESSAGE], NULL);
}

/* TcpAcknowledgeMessage */
static UA_INLINE size_t
UA_TcpAcknowledgeMessage_calcSizeBinary(const UA_TcpAcknowledgeMessage *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE]);
}
static UA_INLINE UA_StatusCode
UA_TcpAcknowledgeMessage_encodeBinary(const UA_TcpAcknowledgeMessage *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TcpAcknowledgeMessage_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TcpAcknowledgeMessage *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE], NULL);
}

/* TcpErrorMessage */
static UA_INLINE size_t
UA_TcpErrorMessage_calcSizeBinary(const UA_TcpErrorMessage *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE]);
}
static UA_INLINE UA_StatusCode
UA_TcpErrorMessage_encodeBinary(const UA_TcpErrorMessage *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TcpErrorMessage_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TcpErrorMessage *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_TCPERRORMESSAGE], NULL);
}

/* AsymmetricAlgorithmSecurityHeader */
static UA_INLINE size_t
UA_AsymmetricAlgorithmSecurityHeader_calcSizeBinary(const UA_AsymmetricAlgorithmSecurityHeader *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER]);
}
static UA_INLINE UA_StatusCode
UA_AsymmetricAlgorithmSecurityHeader_encodeBinary(const UA_AsymmetricAlgorithmSecurityHeader *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AsymmetricAlgorithmSecurityHeader_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AsymmetricAlgorithmSecurityHeader *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER], NULL);
}

/* SequenceHeader */
static UA_INLINE size_t
UA_SequenceHeader_calcSizeBinary(const UA_SequenceHeader *src) {
    return UA_calcSizeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_SEQUENCEHEADER]);
}
static UA_INLINE UA_StatusCode
UA_SequenceHeader_encodeBinary(const UA_SequenceHeader *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TRANSPORT[UA_TRANSPORT_SEQUENCEHEADER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SequenceHeader_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SequenceHeader *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TRANSPORT[UA_TRANSPORT_SEQUENCEHEADER], NULL);
}

#endif /* TRANSPORT_GENERATED_ENCODING_BINARY_H_ */
