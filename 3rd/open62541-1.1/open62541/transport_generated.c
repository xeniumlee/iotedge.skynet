/* Generated from Opc.Ua.Types.bsd, Custom.Opc.Ua.Transport.bsd with script /root/edge/open62541/tools/generate_datatypes.py
 * on host jayli by user root at 2020-06-17 04:03:31 */

#include "transport_generated.h"

/* MessageType */
#define MessageType_members NULL

/* ChunkType */
#define ChunkType_members NULL

/* TcpMessageHeader */
static UA_DataTypeMember TcpMessageHeader_members[2] = {
{
    UA_TYPENAME("MessageTypeAndChunkType") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("MessageSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpMessageHeader, messageSize) - offsetof(UA_TcpMessageHeader, messageTypeAndChunkType) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};

/* TcpHelloMessage */
static UA_DataTypeMember TcpHelloMessage_members[6] = {
{
    UA_TYPENAME("ProtocolVersion") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("ReceiveBufferSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpHelloMessage, receiveBufferSize) - offsetof(UA_TcpHelloMessage, protocolVersion) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("SendBufferSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpHelloMessage, sendBufferSize) - offsetof(UA_TcpHelloMessage, receiveBufferSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("MaxMessageSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpHelloMessage, maxMessageSize) - offsetof(UA_TcpHelloMessage, sendBufferSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("MaxChunkCount") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpHelloMessage, maxChunkCount) - offsetof(UA_TcpHelloMessage, maxMessageSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("EndpointUrl") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_TcpHelloMessage, endpointUrl) - offsetof(UA_TcpHelloMessage, maxChunkCount) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};

/* TcpAcknowledgeMessage */
static UA_DataTypeMember TcpAcknowledgeMessage_members[5] = {
{
    UA_TYPENAME("ProtocolVersion") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("ReceiveBufferSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpAcknowledgeMessage, receiveBufferSize) - offsetof(UA_TcpAcknowledgeMessage, protocolVersion) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("SendBufferSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpAcknowledgeMessage, sendBufferSize) - offsetof(UA_TcpAcknowledgeMessage, receiveBufferSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("MaxMessageSize") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpAcknowledgeMessage, maxMessageSize) - offsetof(UA_TcpAcknowledgeMessage, sendBufferSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("MaxChunkCount") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_TcpAcknowledgeMessage, maxChunkCount) - offsetof(UA_TcpAcknowledgeMessage, maxMessageSize) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};

/* TcpErrorMessage */
static UA_DataTypeMember TcpErrorMessage_members[2] = {
{
    UA_TYPENAME("Error") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("Reason") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_TcpErrorMessage, reason) - offsetof(UA_TcpErrorMessage, error) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};

/* AsymmetricAlgorithmSecurityHeader */
static UA_DataTypeMember AsymmetricAlgorithmSecurityHeader_members[3] = {
{
    UA_TYPENAME("SecurityPolicyUri") /* .memberName */
    UA_TYPES_BYTESTRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("SenderCertificate") /* .memberName */
    UA_TYPES_BYTESTRING, /* .memberTypeIndex */
    offsetof(UA_AsymmetricAlgorithmSecurityHeader, senderCertificate) - offsetof(UA_AsymmetricAlgorithmSecurityHeader, securityPolicyUri) - sizeof(UA_ByteString), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("ReceiverCertificateThumbprint") /* .memberName */
    UA_TYPES_BYTESTRING, /* .memberTypeIndex */
    offsetof(UA_AsymmetricAlgorithmSecurityHeader, receiverCertificateThumbprint) - offsetof(UA_AsymmetricAlgorithmSecurityHeader, senderCertificate) - sizeof(UA_ByteString), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};

/* SequenceHeader */
static UA_DataTypeMember SequenceHeader_members[2] = {
{
    UA_TYPENAME("SequenceNumber") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},
{
    UA_TYPENAME("RequestId") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_SequenceHeader, requestId) - offsetof(UA_SequenceHeader, sequenceNumber) - sizeof(UA_UInt32), /* .padding */
    true, /* .namespaceZero */
    false, /* .isArray */
    false /* .isOptional */
},};
const UA_DataType UA_TRANSPORT[UA_TRANSPORT_COUNT] = {
/* MessageType */
{
    UA_TYPENAME("MessageType") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_MessageType), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    MessageType_members /* .members */
},
/* ChunkType */
{
    UA_TYPENAME("ChunkType") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_ChunkType), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    ChunkType_members /* .members */
},
/* TcpMessageHeader */
{
    UA_TYPENAME("TcpMessageHeader") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_TcpMessageHeader), /* .memSize */
    UA_TRANSPORT_TCPMESSAGEHEADER, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    true, /* .pointerFree */
    false, /* .overlayable */
    2, /* .membersSize */
    0, /* .binaryEncodingId */
    TcpMessageHeader_members /* .members */
},
/* TcpHelloMessage */
{
    UA_TYPENAME("TcpHelloMessage") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_TcpHelloMessage), /* .memSize */
    UA_TRANSPORT_TCPHELLOMESSAGE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    6, /* .membersSize */
    0, /* .binaryEncodingId */
    TcpHelloMessage_members /* .members */
},
/* TcpAcknowledgeMessage */
{
    UA_TYPENAME("TcpAcknowledgeMessage") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_TcpAcknowledgeMessage), /* .memSize */
    UA_TRANSPORT_TCPACKNOWLEDGEMESSAGE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    true, /* .pointerFree */
    false, /* .overlayable */
    5, /* .membersSize */
    0, /* .binaryEncodingId */
    TcpAcknowledgeMessage_members /* .members */
},
/* TcpErrorMessage */
{
    UA_TYPENAME("TcpErrorMessage") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_TcpErrorMessage), /* .memSize */
    UA_TRANSPORT_TCPERRORMESSAGE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    2, /* .membersSize */
    0, /* .binaryEncodingId */
    TcpErrorMessage_members /* .members */
},
/* AsymmetricAlgorithmSecurityHeader */
{
    UA_TYPENAME("AsymmetricAlgorithmSecurityHeader") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_AsymmetricAlgorithmSecurityHeader), /* .memSize */
    UA_TRANSPORT_ASYMMETRICALGORITHMSECURITYHEADER, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    3, /* .membersSize */
    0, /* .binaryEncodingId */
    AsymmetricAlgorithmSecurityHeader_members /* .members */
},
/* SequenceHeader */
{
    UA_TYPENAME("SequenceHeader") /* .typeName */
    {0, UA_NODEIDTYPE_NUMERIC, {0}}, /* .typeId */
    sizeof(UA_SequenceHeader), /* .memSize */
    UA_TRANSPORT_SEQUENCEHEADER, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    true, /* .pointerFree */
    false, /* .overlayable */
    2, /* .membersSize */
    0, /* .binaryEncodingId */
    SequenceHeader_members /* .members */
},
};

