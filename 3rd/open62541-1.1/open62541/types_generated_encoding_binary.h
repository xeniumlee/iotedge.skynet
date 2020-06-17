/* Generated from Opc.Ua.Types.bsd with script /root/edge/open62541/tools/generate_datatypes.py
 * on host jayli by user root at 2020-06-17 04:03:31 */

#ifndef TYPES_GENERATED_ENCODING_BINARY_H_
#define TYPES_GENERATED_ENCODING_BINARY_H_

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else
# include "ua_types_encoding_binary.h"
# include "types_generated.h"
#endif



/* Boolean */
static UA_INLINE size_t
UA_Boolean_calcSizeBinary(const UA_Boolean *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BOOLEAN]);
}
static UA_INLINE UA_StatusCode
UA_Boolean_encodeBinary(const UA_Boolean *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BOOLEAN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Boolean_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Boolean *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BOOLEAN], NULL);
}

/* SByte */
static UA_INLINE size_t
UA_SByte_calcSizeBinary(const UA_SByte *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SBYTE]);
}
static UA_INLINE UA_StatusCode
UA_SByte_encodeBinary(const UA_SByte *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SBYTE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SByte_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SByte *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SBYTE], NULL);
}

/* Byte */
static UA_INLINE size_t
UA_Byte_calcSizeBinary(const UA_Byte *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BYTE]);
}
static UA_INLINE UA_StatusCode
UA_Byte_encodeBinary(const UA_Byte *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BYTE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Byte_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Byte *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BYTE], NULL);
}

/* Int16 */
static UA_INLINE size_t
UA_Int16_calcSizeBinary(const UA_Int16 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_INT16]);
}
static UA_INLINE UA_StatusCode
UA_Int16_encodeBinary(const UA_Int16 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_INT16], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Int16_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Int16 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_INT16], NULL);
}

/* UInt16 */
static UA_INLINE size_t
UA_UInt16_calcSizeBinary(const UA_UInt16 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UINT16]);
}
static UA_INLINE UA_StatusCode
UA_UInt16_encodeBinary(const UA_UInt16 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UINT16], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UInt16_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UInt16 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UINT16], NULL);
}

/* Int32 */
static UA_INLINE size_t
UA_Int32_calcSizeBinary(const UA_Int32 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_INT32]);
}
static UA_INLINE UA_StatusCode
UA_Int32_encodeBinary(const UA_Int32 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_INT32], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Int32_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Int32 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_INT32], NULL);
}

/* UInt32 */
static UA_INLINE size_t
UA_UInt32_calcSizeBinary(const UA_UInt32 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UINT32]);
}
static UA_INLINE UA_StatusCode
UA_UInt32_encodeBinary(const UA_UInt32 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UINT32], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UInt32_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UInt32 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UINT32], NULL);
}

/* Int64 */
static UA_INLINE size_t
UA_Int64_calcSizeBinary(const UA_Int64 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_INT64]);
}
static UA_INLINE UA_StatusCode
UA_Int64_encodeBinary(const UA_Int64 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_INT64], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Int64_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Int64 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_INT64], NULL);
}

/* UInt64 */
static UA_INLINE size_t
UA_UInt64_calcSizeBinary(const UA_UInt64 *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UINT64]);
}
static UA_INLINE UA_StatusCode
UA_UInt64_encodeBinary(const UA_UInt64 *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UINT64], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UInt64_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UInt64 *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UINT64], NULL);
}

/* Float */
static UA_INLINE size_t
UA_Float_calcSizeBinary(const UA_Float *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FLOAT]);
}
static UA_INLINE UA_StatusCode
UA_Float_encodeBinary(const UA_Float *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FLOAT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Float_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Float *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FLOAT], NULL);
}

/* Double */
static UA_INLINE size_t
UA_Double_calcSizeBinary(const UA_Double *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DOUBLE]);
}
static UA_INLINE UA_StatusCode
UA_Double_encodeBinary(const UA_Double *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DOUBLE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Double_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Double *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DOUBLE], NULL);
}

/* String */
static UA_INLINE size_t
UA_String_calcSizeBinary(const UA_String *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STRING]);
}
static UA_INLINE UA_StatusCode
UA_String_encodeBinary(const UA_String *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STRING], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_String_decodeBinary(const UA_ByteString *src, size_t *offset, UA_String *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STRING], NULL);
}

/* DateTime */
static UA_INLINE size_t
UA_DateTime_calcSizeBinary(const UA_DateTime *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATETIME]);
}
static UA_INLINE UA_StatusCode
UA_DateTime_encodeBinary(const UA_DateTime *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATETIME], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DateTime_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DateTime *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATETIME], NULL);
}

/* Guid */
static UA_INLINE size_t
UA_Guid_calcSizeBinary(const UA_Guid *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_GUID]);
}
static UA_INLINE UA_StatusCode
UA_Guid_encodeBinary(const UA_Guid *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_GUID], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Guid_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Guid *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_GUID], NULL);
}

/* ByteString */
static UA_INLINE size_t
UA_ByteString_calcSizeBinary(const UA_ByteString *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BYTESTRING]);
}
static UA_INLINE UA_StatusCode
UA_ByteString_encodeBinary(const UA_ByteString *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BYTESTRING], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ByteString_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ByteString *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BYTESTRING], NULL);
}

/* XmlElement */
static UA_INLINE size_t
UA_XmlElement_calcSizeBinary(const UA_XmlElement *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_XMLELEMENT]);
}
static UA_INLINE UA_StatusCode
UA_XmlElement_encodeBinary(const UA_XmlElement *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_XMLELEMENT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_XmlElement_decodeBinary(const UA_ByteString *src, size_t *offset, UA_XmlElement *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_XMLELEMENT], NULL);
}

/* NodeId */
static UA_INLINE size_t
UA_NodeId_calcSizeBinary(const UA_NodeId *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_NODEID]);
}
static UA_INLINE UA_StatusCode
UA_NodeId_encodeBinary(const UA_NodeId *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_NODEID], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NodeId_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NodeId *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_NODEID], NULL);
}

/* ExpandedNodeId */
static UA_INLINE size_t
UA_ExpandedNodeId_calcSizeBinary(const UA_ExpandedNodeId *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EXPANDEDNODEID]);
}
static UA_INLINE UA_StatusCode
UA_ExpandedNodeId_encodeBinary(const UA_ExpandedNodeId *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EXPANDEDNODEID], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ExpandedNodeId_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ExpandedNodeId *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EXPANDEDNODEID], NULL);
}

/* StatusCode */
static UA_INLINE size_t
UA_StatusCode_calcSizeBinary(const UA_StatusCode *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STATUSCODE]);
}
static UA_INLINE UA_StatusCode
UA_StatusCode_encodeBinary(const UA_StatusCode *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STATUSCODE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StatusCode_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StatusCode *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STATUSCODE], NULL);
}

/* QualifiedName */
static UA_INLINE size_t
UA_QualifiedName_calcSizeBinary(const UA_QualifiedName *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_QUALIFIEDNAME]);
}
static UA_INLINE UA_StatusCode
UA_QualifiedName_encodeBinary(const UA_QualifiedName *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_QUALIFIEDNAME], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_QualifiedName_decodeBinary(const UA_ByteString *src, size_t *offset, UA_QualifiedName *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_QUALIFIEDNAME], NULL);
}

/* LocalizedText */
static UA_INLINE size_t
UA_LocalizedText_calcSizeBinary(const UA_LocalizedText *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
}
static UA_INLINE UA_StatusCode
UA_LocalizedText_encodeBinary(const UA_LocalizedText *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LocalizedText_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LocalizedText *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT], NULL);
}

/* ExtensionObject */
static UA_INLINE size_t
UA_ExtensionObject_calcSizeBinary(const UA_ExtensionObject *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT]);
}
static UA_INLINE UA_StatusCode
UA_ExtensionObject_encodeBinary(const UA_ExtensionObject *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ExtensionObject_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ExtensionObject *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EXTENSIONOBJECT], NULL);
}

/* DataValue */
static UA_INLINE size_t
UA_DataValue_calcSizeBinary(const UA_DataValue *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATAVALUE]);
}
static UA_INLINE UA_StatusCode
UA_DataValue_encodeBinary(const UA_DataValue *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATAVALUE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DataValue_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DataValue *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATAVALUE], NULL);
}

/* Variant */
static UA_INLINE size_t
UA_Variant_calcSizeBinary(const UA_Variant *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_VARIANT]);
}
static UA_INLINE UA_StatusCode
UA_Variant_encodeBinary(const UA_Variant *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_VARIANT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Variant_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Variant *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_VARIANT], NULL);
}

/* DiagnosticInfo */
static UA_INLINE size_t
UA_DiagnosticInfo_calcSizeBinary(const UA_DiagnosticInfo *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DIAGNOSTICINFO]);
}
static UA_INLINE UA_StatusCode
UA_DiagnosticInfo_encodeBinary(const UA_DiagnosticInfo *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DIAGNOSTICINFO], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DiagnosticInfo_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DiagnosticInfo *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DIAGNOSTICINFO], NULL);
}

/* NodeClass */
static UA_INLINE size_t
UA_NodeClass_calcSizeBinary(const UA_NodeClass *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_NODECLASS]);
}
static UA_INLINE UA_StatusCode
UA_NodeClass_encodeBinary(const UA_NodeClass *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_NODECLASS], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NodeClass_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NodeClass *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_NODECLASS], NULL);
}

/* StructureType */
static UA_INLINE size_t
UA_StructureType_calcSizeBinary(const UA_StructureType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STRUCTURETYPE]);
}
static UA_INLINE UA_StatusCode
UA_StructureType_encodeBinary(const UA_StructureType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STRUCTURETYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StructureType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StructureType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STRUCTURETYPE], NULL);
}

/* StructureField */
static UA_INLINE size_t
UA_StructureField_calcSizeBinary(const UA_StructureField *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STRUCTUREFIELD]);
}
static UA_INLINE UA_StatusCode
UA_StructureField_encodeBinary(const UA_StructureField *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STRUCTUREFIELD], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StructureField_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StructureField *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STRUCTUREFIELD], NULL);
}

/* StructureDefinition */
static UA_INLINE size_t
UA_StructureDefinition_calcSizeBinary(const UA_StructureDefinition *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STRUCTUREDEFINITION]);
}
static UA_INLINE UA_StatusCode
UA_StructureDefinition_encodeBinary(const UA_StructureDefinition *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STRUCTUREDEFINITION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StructureDefinition_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StructureDefinition *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STRUCTUREDEFINITION], NULL);
}

/* Argument */
static UA_INLINE size_t
UA_Argument_calcSizeBinary(const UA_Argument *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ARGUMENT]);
}
static UA_INLINE UA_StatusCode
UA_Argument_encodeBinary(const UA_Argument *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ARGUMENT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Argument_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Argument *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ARGUMENT], NULL);
}

/* EnumValueType */
static UA_INLINE size_t
UA_EnumValueType_calcSizeBinary(const UA_EnumValueType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
}
static UA_INLINE UA_StatusCode
UA_EnumValueType_encodeBinary(const UA_EnumValueType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ENUMVALUETYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EnumValueType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EnumValueType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ENUMVALUETYPE], NULL);
}

/* EnumField */
static UA_INLINE size_t
UA_EnumField_calcSizeBinary(const UA_EnumField *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ENUMFIELD]);
}
static UA_INLINE UA_StatusCode
UA_EnumField_encodeBinary(const UA_EnumField *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ENUMFIELD], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EnumField_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EnumField *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ENUMFIELD], NULL);
}

/* Duration */
static UA_INLINE size_t
UA_Duration_calcSizeBinary(const UA_Duration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DURATION]);
}
static UA_INLINE UA_StatusCode
UA_Duration_encodeBinary(const UA_Duration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DURATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Duration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Duration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DURATION], NULL);
}

/* UtcTime */
static UA_INLINE size_t
UA_UtcTime_calcSizeBinary(const UA_UtcTime *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UTCTIME]);
}
static UA_INLINE UA_StatusCode
UA_UtcTime_encodeBinary(const UA_UtcTime *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UTCTIME], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UtcTime_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UtcTime *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UTCTIME], NULL);
}

/* LocaleId */
static UA_INLINE size_t
UA_LocaleId_calcSizeBinary(const UA_LocaleId *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_LOCALEID]);
}
static UA_INLINE UA_StatusCode
UA_LocaleId_encodeBinary(const UA_LocaleId *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_LOCALEID], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LocaleId_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LocaleId *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_LOCALEID], NULL);
}

/* ApplicationType */
static UA_INLINE size_t
UA_ApplicationType_calcSizeBinary(const UA_ApplicationType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_APPLICATIONTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ApplicationType_encodeBinary(const UA_ApplicationType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_APPLICATIONTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ApplicationType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ApplicationType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_APPLICATIONTYPE], NULL);
}

/* ApplicationDescription */
static UA_INLINE size_t
UA_ApplicationDescription_calcSizeBinary(const UA_ApplicationDescription *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_APPLICATIONDESCRIPTION]);
}
static UA_INLINE UA_StatusCode
UA_ApplicationDescription_encodeBinary(const UA_ApplicationDescription *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_APPLICATIONDESCRIPTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ApplicationDescription_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ApplicationDescription *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_APPLICATIONDESCRIPTION], NULL);
}

/* RequestHeader */
static UA_INLINE size_t
UA_RequestHeader_calcSizeBinary(const UA_RequestHeader *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REQUESTHEADER]);
}
static UA_INLINE UA_StatusCode
UA_RequestHeader_encodeBinary(const UA_RequestHeader *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REQUESTHEADER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RequestHeader_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RequestHeader *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REQUESTHEADER], NULL);
}

/* ResponseHeader */
static UA_INLINE size_t
UA_ResponseHeader_calcSizeBinary(const UA_ResponseHeader *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_RESPONSEHEADER]);
}
static UA_INLINE UA_StatusCode
UA_ResponseHeader_encodeBinary(const UA_ResponseHeader *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_RESPONSEHEADER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ResponseHeader_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ResponseHeader *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_RESPONSEHEADER], NULL);
}

/* ServiceFault */
static UA_INLINE size_t
UA_ServiceFault_calcSizeBinary(const UA_ServiceFault *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SERVICEFAULT]);
}
static UA_INLINE UA_StatusCode
UA_ServiceFault_encodeBinary(const UA_ServiceFault *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SERVICEFAULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ServiceFault_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ServiceFault *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SERVICEFAULT], NULL);
}

/* FindServersRequest */
static UA_INLINE size_t
UA_FindServersRequest_calcSizeBinary(const UA_FindServersRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_FindServersRequest_encodeBinary(const UA_FindServersRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FindServersRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FindServersRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FINDSERVERSREQUEST], NULL);
}

/* FindServersResponse */
static UA_INLINE size_t
UA_FindServersResponse_calcSizeBinary(const UA_FindServersResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_FindServersResponse_encodeBinary(const UA_FindServersResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FindServersResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FindServersResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FINDSERVERSRESPONSE], NULL);
}

/* ServerOnNetwork */
static UA_INLINE size_t
UA_ServerOnNetwork_calcSizeBinary(const UA_ServerOnNetwork *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SERVERONNETWORK]);
}
static UA_INLINE UA_StatusCode
UA_ServerOnNetwork_encodeBinary(const UA_ServerOnNetwork *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SERVERONNETWORK], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ServerOnNetwork_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ServerOnNetwork *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SERVERONNETWORK], NULL);
}

/* FindServersOnNetworkRequest */
static UA_INLINE size_t
UA_FindServersOnNetworkRequest_calcSizeBinary(const UA_FindServersOnNetworkRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_FindServersOnNetworkRequest_encodeBinary(const UA_FindServersOnNetworkRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FindServersOnNetworkRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FindServersOnNetworkRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKREQUEST], NULL);
}

/* FindServersOnNetworkResponse */
static UA_INLINE size_t
UA_FindServersOnNetworkResponse_calcSizeBinary(const UA_FindServersOnNetworkResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_FindServersOnNetworkResponse_encodeBinary(const UA_FindServersOnNetworkResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FindServersOnNetworkResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FindServersOnNetworkResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FINDSERVERSONNETWORKRESPONSE], NULL);
}

/* MessageSecurityMode */
static UA_INLINE size_t
UA_MessageSecurityMode_calcSizeBinary(const UA_MessageSecurityMode *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MESSAGESECURITYMODE]);
}
static UA_INLINE UA_StatusCode
UA_MessageSecurityMode_encodeBinary(const UA_MessageSecurityMode *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MESSAGESECURITYMODE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MessageSecurityMode_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MessageSecurityMode *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MESSAGESECURITYMODE], NULL);
}

/* UserTokenType */
static UA_INLINE size_t
UA_UserTokenType_calcSizeBinary(const UA_UserTokenType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_USERTOKENTYPE]);
}
static UA_INLINE UA_StatusCode
UA_UserTokenType_encodeBinary(const UA_UserTokenType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_USERTOKENTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UserTokenType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UserTokenType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_USERTOKENTYPE], NULL);
}

/* UserTokenPolicy */
static UA_INLINE size_t
UA_UserTokenPolicy_calcSizeBinary(const UA_UserTokenPolicy *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_USERTOKENPOLICY]);
}
static UA_INLINE UA_StatusCode
UA_UserTokenPolicy_encodeBinary(const UA_UserTokenPolicy *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_USERTOKENPOLICY], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UserTokenPolicy_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UserTokenPolicy *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_USERTOKENPOLICY], NULL);
}

/* EndpointDescription */
static UA_INLINE size_t
UA_EndpointDescription_calcSizeBinary(const UA_EndpointDescription *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
}
static UA_INLINE UA_StatusCode
UA_EndpointDescription_encodeBinary(const UA_EndpointDescription *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EndpointDescription_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EndpointDescription *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION], NULL);
}

/* GetEndpointsRequest */
static UA_INLINE size_t
UA_GetEndpointsRequest_calcSizeBinary(const UA_GetEndpointsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_GETENDPOINTSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_GetEndpointsRequest_encodeBinary(const UA_GetEndpointsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_GETENDPOINTSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_GetEndpointsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_GetEndpointsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_GETENDPOINTSREQUEST], NULL);
}

/* GetEndpointsResponse */
static UA_INLINE size_t
UA_GetEndpointsResponse_calcSizeBinary(const UA_GetEndpointsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_GETENDPOINTSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_GetEndpointsResponse_encodeBinary(const UA_GetEndpointsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_GETENDPOINTSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_GetEndpointsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_GetEndpointsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_GETENDPOINTSRESPONSE], NULL);
}

/* RegisteredServer */
static UA_INLINE size_t
UA_RegisteredServer_calcSizeBinary(const UA_RegisteredServer *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTEREDSERVER]);
}
static UA_INLINE UA_StatusCode
UA_RegisteredServer_encodeBinary(const UA_RegisteredServer *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTEREDSERVER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisteredServer_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisteredServer *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTEREDSERVER], NULL);
}

/* RegisterServerRequest */
static UA_INLINE size_t
UA_RegisterServerRequest_calcSizeBinary(const UA_RegisterServerRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVERREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_RegisterServerRequest_encodeBinary(const UA_RegisterServerRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVERREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterServerRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterServerRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERSERVERREQUEST], NULL);
}

/* RegisterServerResponse */
static UA_INLINE size_t
UA_RegisterServerResponse_calcSizeBinary(const UA_RegisterServerResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVERRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_RegisterServerResponse_encodeBinary(const UA_RegisterServerResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVERRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterServerResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterServerResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERSERVERRESPONSE], NULL);
}

/* DiscoveryConfiguration */
static UA_INLINE size_t
UA_DiscoveryConfiguration_calcSizeBinary(const UA_DiscoveryConfiguration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DISCOVERYCONFIGURATION]);
}
static UA_INLINE UA_StatusCode
UA_DiscoveryConfiguration_encodeBinary(const UA_DiscoveryConfiguration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DISCOVERYCONFIGURATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DiscoveryConfiguration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DiscoveryConfiguration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DISCOVERYCONFIGURATION], NULL);
}

/* MdnsDiscoveryConfiguration */
static UA_INLINE size_t
UA_MdnsDiscoveryConfiguration_calcSizeBinary(const UA_MdnsDiscoveryConfiguration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MDNSDISCOVERYCONFIGURATION]);
}
static UA_INLINE UA_StatusCode
UA_MdnsDiscoveryConfiguration_encodeBinary(const UA_MdnsDiscoveryConfiguration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MDNSDISCOVERYCONFIGURATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MdnsDiscoveryConfiguration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MdnsDiscoveryConfiguration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MDNSDISCOVERYCONFIGURATION], NULL);
}

/* RegisterServer2Request */
static UA_INLINE size_t
UA_RegisterServer2Request_calcSizeBinary(const UA_RegisterServer2Request *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVER2REQUEST]);
}
static UA_INLINE UA_StatusCode
UA_RegisterServer2Request_encodeBinary(const UA_RegisterServer2Request *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVER2REQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterServer2Request_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterServer2Request *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERSERVER2REQUEST], NULL);
}

/* RegisterServer2Response */
static UA_INLINE size_t
UA_RegisterServer2Response_calcSizeBinary(const UA_RegisterServer2Response *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVER2RESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_RegisterServer2Response_encodeBinary(const UA_RegisterServer2Response *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERSERVER2RESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterServer2Response_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterServer2Response *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERSERVER2RESPONSE], NULL);
}

/* SecurityTokenRequestType */
static UA_INLINE size_t
UA_SecurityTokenRequestType_calcSizeBinary(const UA_SecurityTokenRequestType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SECURITYTOKENREQUESTTYPE]);
}
static UA_INLINE UA_StatusCode
UA_SecurityTokenRequestType_encodeBinary(const UA_SecurityTokenRequestType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SECURITYTOKENREQUESTTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SecurityTokenRequestType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SecurityTokenRequestType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SECURITYTOKENREQUESTTYPE], NULL);
}

/* ChannelSecurityToken */
static UA_INLINE size_t
UA_ChannelSecurityToken_calcSizeBinary(const UA_ChannelSecurityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CHANNELSECURITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_ChannelSecurityToken_encodeBinary(const UA_ChannelSecurityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CHANNELSECURITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ChannelSecurityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ChannelSecurityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CHANNELSECURITYTOKEN], NULL);
}

/* OpenSecureChannelRequest */
static UA_INLINE size_t
UA_OpenSecureChannelRequest_calcSizeBinary(const UA_OpenSecureChannelRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_OPENSECURECHANNELREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_OpenSecureChannelRequest_encodeBinary(const UA_OpenSecureChannelRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_OPENSECURECHANNELREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_OpenSecureChannelRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_OpenSecureChannelRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_OPENSECURECHANNELREQUEST], NULL);
}

/* OpenSecureChannelResponse */
static UA_INLINE size_t
UA_OpenSecureChannelResponse_calcSizeBinary(const UA_OpenSecureChannelResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_OPENSECURECHANNELRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_OpenSecureChannelResponse_encodeBinary(const UA_OpenSecureChannelResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_OPENSECURECHANNELRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_OpenSecureChannelResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_OpenSecureChannelResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_OPENSECURECHANNELRESPONSE], NULL);
}

/* CloseSecureChannelRequest */
static UA_INLINE size_t
UA_CloseSecureChannelRequest_calcSizeBinary(const UA_CloseSecureChannelRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CloseSecureChannelRequest_encodeBinary(const UA_CloseSecureChannelRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CloseSecureChannelRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CloseSecureChannelRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELREQUEST], NULL);
}

/* CloseSecureChannelResponse */
static UA_INLINE size_t
UA_CloseSecureChannelResponse_calcSizeBinary(const UA_CloseSecureChannelResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CloseSecureChannelResponse_encodeBinary(const UA_CloseSecureChannelResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CloseSecureChannelResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CloseSecureChannelResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CLOSESECURECHANNELRESPONSE], NULL);
}

/* SignedSoftwareCertificate */
static UA_INLINE size_t
UA_SignedSoftwareCertificate_calcSizeBinary(const UA_SignedSoftwareCertificate *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SIGNEDSOFTWARECERTIFICATE]);
}
static UA_INLINE UA_StatusCode
UA_SignedSoftwareCertificate_encodeBinary(const UA_SignedSoftwareCertificate *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SIGNEDSOFTWARECERTIFICATE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SignedSoftwareCertificate_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SignedSoftwareCertificate *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SIGNEDSOFTWARECERTIFICATE], NULL);
}

/* SignatureData */
static UA_INLINE size_t
UA_SignatureData_calcSizeBinary(const UA_SignatureData *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SIGNATUREDATA]);
}
static UA_INLINE UA_StatusCode
UA_SignatureData_encodeBinary(const UA_SignatureData *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SIGNATUREDATA], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SignatureData_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SignatureData *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SIGNATUREDATA], NULL);
}

/* CreateSessionRequest */
static UA_INLINE size_t
UA_CreateSessionRequest_calcSizeBinary(const UA_CreateSessionRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATESESSIONREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CreateSessionRequest_encodeBinary(const UA_CreateSessionRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATESESSIONREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateSessionRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateSessionRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATESESSIONREQUEST], NULL);
}

/* CreateSessionResponse */
static UA_INLINE size_t
UA_CreateSessionResponse_calcSizeBinary(const UA_CreateSessionResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATESESSIONRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CreateSessionResponse_encodeBinary(const UA_CreateSessionResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATESESSIONRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateSessionResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateSessionResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATESESSIONRESPONSE], NULL);
}

/* UserIdentityToken */
static UA_INLINE size_t
UA_UserIdentityToken_calcSizeBinary(const UA_UserIdentityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_USERIDENTITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_UserIdentityToken_encodeBinary(const UA_UserIdentityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_USERIDENTITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UserIdentityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UserIdentityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_USERIDENTITYTOKEN], NULL);
}

/* AnonymousIdentityToken */
static UA_INLINE size_t
UA_AnonymousIdentityToken_calcSizeBinary(const UA_AnonymousIdentityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ANONYMOUSIDENTITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_AnonymousIdentityToken_encodeBinary(const UA_AnonymousIdentityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ANONYMOUSIDENTITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AnonymousIdentityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AnonymousIdentityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ANONYMOUSIDENTITYTOKEN], NULL);
}

/* UserNameIdentityToken */
static UA_INLINE size_t
UA_UserNameIdentityToken_calcSizeBinary(const UA_UserNameIdentityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_USERNAMEIDENTITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_UserNameIdentityToken_encodeBinary(const UA_UserNameIdentityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_USERNAMEIDENTITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UserNameIdentityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UserNameIdentityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_USERNAMEIDENTITYTOKEN], NULL);
}

/* X509IdentityToken */
static UA_INLINE size_t
UA_X509IdentityToken_calcSizeBinary(const UA_X509IdentityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_X509IDENTITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_X509IdentityToken_encodeBinary(const UA_X509IdentityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_X509IDENTITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_X509IdentityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_X509IdentityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_X509IDENTITYTOKEN], NULL);
}

/* IssuedIdentityToken */
static UA_INLINE size_t
UA_IssuedIdentityToken_calcSizeBinary(const UA_IssuedIdentityToken *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ISSUEDIDENTITYTOKEN]);
}
static UA_INLINE UA_StatusCode
UA_IssuedIdentityToken_encodeBinary(const UA_IssuedIdentityToken *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ISSUEDIDENTITYTOKEN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_IssuedIdentityToken_decodeBinary(const UA_ByteString *src, size_t *offset, UA_IssuedIdentityToken *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ISSUEDIDENTITYTOKEN], NULL);
}

/* ActivateSessionRequest */
static UA_INLINE size_t
UA_ActivateSessionRequest_calcSizeBinary(const UA_ActivateSessionRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ACTIVATESESSIONREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_ActivateSessionRequest_encodeBinary(const UA_ActivateSessionRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ACTIVATESESSIONREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ActivateSessionRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ActivateSessionRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ACTIVATESESSIONREQUEST], NULL);
}

/* ActivateSessionResponse */
static UA_INLINE size_t
UA_ActivateSessionResponse_calcSizeBinary(const UA_ActivateSessionResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ACTIVATESESSIONRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_ActivateSessionResponse_encodeBinary(const UA_ActivateSessionResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ACTIVATESESSIONRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ActivateSessionResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ActivateSessionResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ACTIVATESESSIONRESPONSE], NULL);
}

/* CloseSessionRequest */
static UA_INLINE size_t
UA_CloseSessionRequest_calcSizeBinary(const UA_CloseSessionRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CLOSESESSIONREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CloseSessionRequest_encodeBinary(const UA_CloseSessionRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CLOSESESSIONREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CloseSessionRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CloseSessionRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CLOSESESSIONREQUEST], NULL);
}

/* CloseSessionResponse */
static UA_INLINE size_t
UA_CloseSessionResponse_calcSizeBinary(const UA_CloseSessionResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CLOSESESSIONRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CloseSessionResponse_encodeBinary(const UA_CloseSessionResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CLOSESESSIONRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CloseSessionResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CloseSessionResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CLOSESESSIONRESPONSE], NULL);
}

/* NodeAttributesMask */
static UA_INLINE size_t
UA_NodeAttributesMask_calcSizeBinary(const UA_NodeAttributesMask *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_NODEATTRIBUTESMASK]);
}
static UA_INLINE UA_StatusCode
UA_NodeAttributesMask_encodeBinary(const UA_NodeAttributesMask *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_NODEATTRIBUTESMASK], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NodeAttributesMask_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NodeAttributesMask *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_NODEATTRIBUTESMASK], NULL);
}

/* NodeAttributes */
static UA_INLINE size_t
UA_NodeAttributes_calcSizeBinary(const UA_NodeAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_NODEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_NodeAttributes_encodeBinary(const UA_NodeAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_NODEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NodeAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NodeAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_NODEATTRIBUTES], NULL);
}

/* ObjectAttributes */
static UA_INLINE size_t
UA_ObjectAttributes_calcSizeBinary(const UA_ObjectAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_ObjectAttributes_encodeBinary(const UA_ObjectAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ObjectAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ObjectAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES], NULL);
}

/* VariableAttributes */
static UA_INLINE size_t
UA_VariableAttributes_calcSizeBinary(const UA_VariableAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_VariableAttributes_encodeBinary(const UA_VariableAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_VariableAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_VariableAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES], NULL);
}

/* MethodAttributes */
static UA_INLINE size_t
UA_MethodAttributes_calcSizeBinary(const UA_MethodAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_METHODATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_MethodAttributes_encodeBinary(const UA_MethodAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_METHODATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MethodAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MethodAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_METHODATTRIBUTES], NULL);
}

/* ObjectTypeAttributes */
static UA_INLINE size_t
UA_ObjectTypeAttributes_calcSizeBinary(const UA_ObjectTypeAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_ObjectTypeAttributes_encodeBinary(const UA_ObjectTypeAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ObjectTypeAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ObjectTypeAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES], NULL);
}

/* VariableTypeAttributes */
static UA_INLINE size_t
UA_VariableTypeAttributes_calcSizeBinary(const UA_VariableTypeAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_VariableTypeAttributes_encodeBinary(const UA_VariableTypeAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_VariableTypeAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_VariableTypeAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES], NULL);
}

/* ReferenceTypeAttributes */
static UA_INLINE size_t
UA_ReferenceTypeAttributes_calcSizeBinary(const UA_ReferenceTypeAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_ReferenceTypeAttributes_encodeBinary(const UA_ReferenceTypeAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ReferenceTypeAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ReferenceTypeAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES], NULL);
}

/* DataTypeAttributes */
static UA_INLINE size_t
UA_DataTypeAttributes_calcSizeBinary(const UA_DataTypeAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_DataTypeAttributes_encodeBinary(const UA_DataTypeAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DataTypeAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DataTypeAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES], NULL);
}

/* ViewAttributes */
static UA_INLINE size_t
UA_ViewAttributes_calcSizeBinary(const UA_ViewAttributes *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_VIEWATTRIBUTES]);
}
static UA_INLINE UA_StatusCode
UA_ViewAttributes_encodeBinary(const UA_ViewAttributes *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_VIEWATTRIBUTES], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ViewAttributes_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ViewAttributes *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_VIEWATTRIBUTES], NULL);
}

/* AddNodesItem */
static UA_INLINE size_t
UA_AddNodesItem_calcSizeBinary(const UA_AddNodesItem *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESITEM]);
}
static UA_INLINE UA_StatusCode
UA_AddNodesItem_encodeBinary(const UA_AddNodesItem *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESITEM], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddNodesItem_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddNodesItem *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDNODESITEM], NULL);
}

/* AddNodesResult */
static UA_INLINE size_t
UA_AddNodesResult_calcSizeBinary(const UA_AddNodesResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESRESULT]);
}
static UA_INLINE UA_StatusCode
UA_AddNodesResult_encodeBinary(const UA_AddNodesResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddNodesResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddNodesResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDNODESRESULT], NULL);
}

/* AddNodesRequest */
static UA_INLINE size_t
UA_AddNodesRequest_calcSizeBinary(const UA_AddNodesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_AddNodesRequest_encodeBinary(const UA_AddNodesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddNodesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddNodesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDNODESREQUEST], NULL);
}

/* AddNodesResponse */
static UA_INLINE size_t
UA_AddNodesResponse_calcSizeBinary(const UA_AddNodesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_AddNodesResponse_encodeBinary(const UA_AddNodesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDNODESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddNodesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddNodesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDNODESRESPONSE], NULL);
}

/* AddReferencesItem */
static UA_INLINE size_t
UA_AddReferencesItem_calcSizeBinary(const UA_AddReferencesItem *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESITEM]);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesItem_encodeBinary(const UA_AddReferencesItem *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESITEM], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesItem_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddReferencesItem *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDREFERENCESITEM], NULL);
}

/* AddReferencesRequest */
static UA_INLINE size_t
UA_AddReferencesRequest_calcSizeBinary(const UA_AddReferencesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesRequest_encodeBinary(const UA_AddReferencesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddReferencesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDREFERENCESREQUEST], NULL);
}

/* AddReferencesResponse */
static UA_INLINE size_t
UA_AddReferencesResponse_calcSizeBinary(const UA_AddReferencesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesResponse_encodeBinary(const UA_AddReferencesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ADDREFERENCESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AddReferencesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AddReferencesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ADDREFERENCESRESPONSE], NULL);
}

/* DeleteNodesItem */
static UA_INLINE size_t
UA_DeleteNodesItem_calcSizeBinary(const UA_DeleteNodesItem *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESITEM]);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesItem_encodeBinary(const UA_DeleteNodesItem *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESITEM], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesItem_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteNodesItem *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETENODESITEM], NULL);
}

/* DeleteNodesRequest */
static UA_INLINE size_t
UA_DeleteNodesRequest_calcSizeBinary(const UA_DeleteNodesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesRequest_encodeBinary(const UA_DeleteNodesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteNodesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETENODESREQUEST], NULL);
}

/* DeleteNodesResponse */
static UA_INLINE size_t
UA_DeleteNodesResponse_calcSizeBinary(const UA_DeleteNodesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesResponse_encodeBinary(const UA_DeleteNodesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETENODESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteNodesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteNodesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETENODESRESPONSE], NULL);
}

/* DeleteReferencesItem */
static UA_INLINE size_t
UA_DeleteReferencesItem_calcSizeBinary(const UA_DeleteReferencesItem *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESITEM]);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesItem_encodeBinary(const UA_DeleteReferencesItem *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESITEM], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesItem_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteReferencesItem *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETEREFERENCESITEM], NULL);
}

/* DeleteReferencesRequest */
static UA_INLINE size_t
UA_DeleteReferencesRequest_calcSizeBinary(const UA_DeleteReferencesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesRequest_encodeBinary(const UA_DeleteReferencesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteReferencesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETEREFERENCESREQUEST], NULL);
}

/* DeleteReferencesResponse */
static UA_INLINE size_t
UA_DeleteReferencesResponse_calcSizeBinary(const UA_DeleteReferencesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesResponse_encodeBinary(const UA_DeleteReferencesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETEREFERENCESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteReferencesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteReferencesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETEREFERENCESRESPONSE], NULL);
}

/* BrowseDirection */
static UA_INLINE size_t
UA_BrowseDirection_calcSizeBinary(const UA_BrowseDirection *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEDIRECTION]);
}
static UA_INLINE UA_StatusCode
UA_BrowseDirection_encodeBinary(const UA_BrowseDirection *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEDIRECTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseDirection_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseDirection *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEDIRECTION], NULL);
}

/* ViewDescription */
static UA_INLINE size_t
UA_ViewDescription_calcSizeBinary(const UA_ViewDescription *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_VIEWDESCRIPTION]);
}
static UA_INLINE UA_StatusCode
UA_ViewDescription_encodeBinary(const UA_ViewDescription *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_VIEWDESCRIPTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ViewDescription_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ViewDescription *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_VIEWDESCRIPTION], NULL);
}

/* BrowseDescription */
static UA_INLINE size_t
UA_BrowseDescription_calcSizeBinary(const UA_BrowseDescription *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEDESCRIPTION]);
}
static UA_INLINE UA_StatusCode
UA_BrowseDescription_encodeBinary(const UA_BrowseDescription *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEDESCRIPTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseDescription_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseDescription *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEDESCRIPTION], NULL);
}

/* BrowseResultMask */
static UA_INLINE size_t
UA_BrowseResultMask_calcSizeBinary(const UA_BrowseResultMask *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESULTMASK]);
}
static UA_INLINE UA_StatusCode
UA_BrowseResultMask_encodeBinary(const UA_BrowseResultMask *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESULTMASK], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseResultMask_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseResultMask *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSERESULTMASK], NULL);
}

/* ReferenceDescription */
static UA_INLINE size_t
UA_ReferenceDescription_calcSizeBinary(const UA_ReferenceDescription *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REFERENCEDESCRIPTION]);
}
static UA_INLINE UA_StatusCode
UA_ReferenceDescription_encodeBinary(const UA_ReferenceDescription *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REFERENCEDESCRIPTION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ReferenceDescription_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ReferenceDescription *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REFERENCEDESCRIPTION], NULL);
}

/* BrowseResult */
static UA_INLINE size_t
UA_BrowseResult_calcSizeBinary(const UA_BrowseResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESULT]);
}
static UA_INLINE UA_StatusCode
UA_BrowseResult_encodeBinary(const UA_BrowseResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSERESULT], NULL);
}

/* BrowseRequest */
static UA_INLINE size_t
UA_BrowseRequest_calcSizeBinary(const UA_BrowseRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_BrowseRequest_encodeBinary(const UA_BrowseRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEREQUEST], NULL);
}

/* BrowseResponse */
static UA_INLINE size_t
UA_BrowseResponse_calcSizeBinary(const UA_BrowseResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_BrowseResponse_encodeBinary(const UA_BrowseResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSERESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSERESPONSE], NULL);
}

/* BrowseNextRequest */
static UA_INLINE size_t
UA_BrowseNextRequest_calcSizeBinary(const UA_BrowseNextRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSENEXTREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_BrowseNextRequest_encodeBinary(const UA_BrowseNextRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSENEXTREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseNextRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseNextRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSENEXTREQUEST], NULL);
}

/* BrowseNextResponse */
static UA_INLINE size_t
UA_BrowseNextResponse_calcSizeBinary(const UA_BrowseNextResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSENEXTRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_BrowseNextResponse_encodeBinary(const UA_BrowseNextResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSENEXTRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowseNextResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowseNextResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSENEXTRESPONSE], NULL);
}

/* RelativePathElement */
static UA_INLINE size_t
UA_RelativePathElement_calcSizeBinary(const UA_RelativePathElement *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_RELATIVEPATHELEMENT]);
}
static UA_INLINE UA_StatusCode
UA_RelativePathElement_encodeBinary(const UA_RelativePathElement *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_RELATIVEPATHELEMENT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RelativePathElement_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RelativePathElement *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_RELATIVEPATHELEMENT], NULL);
}

/* RelativePath */
static UA_INLINE size_t
UA_RelativePath_calcSizeBinary(const UA_RelativePath *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_RELATIVEPATH]);
}
static UA_INLINE UA_StatusCode
UA_RelativePath_encodeBinary(const UA_RelativePath *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_RELATIVEPATH], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RelativePath_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RelativePath *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_RELATIVEPATH], NULL);
}

/* BrowsePath */
static UA_INLINE size_t
UA_BrowsePath_calcSizeBinary(const UA_BrowsePath *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATH]);
}
static UA_INLINE UA_StatusCode
UA_BrowsePath_encodeBinary(const UA_BrowsePath *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATH], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowsePath_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowsePath *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEPATH], NULL);
}

/* BrowsePathTarget */
static UA_INLINE size_t
UA_BrowsePathTarget_calcSizeBinary(const UA_BrowsePathTarget *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATHTARGET]);
}
static UA_INLINE UA_StatusCode
UA_BrowsePathTarget_encodeBinary(const UA_BrowsePathTarget *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATHTARGET], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowsePathTarget_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowsePathTarget *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEPATHTARGET], NULL);
}

/* BrowsePathResult */
static UA_INLINE size_t
UA_BrowsePathResult_calcSizeBinary(const UA_BrowsePathResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATHRESULT]);
}
static UA_INLINE UA_StatusCode
UA_BrowsePathResult_encodeBinary(const UA_BrowsePathResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BROWSEPATHRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BrowsePathResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BrowsePathResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BROWSEPATHRESULT], NULL);
}

/* TranslateBrowsePathsToNodeIdsRequest */
static UA_INLINE size_t
UA_TranslateBrowsePathsToNodeIdsRequest_calcSizeBinary(const UA_TranslateBrowsePathsToNodeIdsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_TranslateBrowsePathsToNodeIdsRequest_encodeBinary(const UA_TranslateBrowsePathsToNodeIdsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TranslateBrowsePathsToNodeIdsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TranslateBrowsePathsToNodeIdsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSREQUEST], NULL);
}

/* TranslateBrowsePathsToNodeIdsResponse */
static UA_INLINE size_t
UA_TranslateBrowsePathsToNodeIdsResponse_calcSizeBinary(const UA_TranslateBrowsePathsToNodeIdsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_TranslateBrowsePathsToNodeIdsResponse_encodeBinary(const UA_TranslateBrowsePathsToNodeIdsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TranslateBrowsePathsToNodeIdsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TranslateBrowsePathsToNodeIdsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_TRANSLATEBROWSEPATHSTONODEIDSRESPONSE], NULL);
}

/* RegisterNodesRequest */
static UA_INLINE size_t
UA_RegisterNodesRequest_calcSizeBinary(const UA_RegisterNodesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERNODESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_RegisterNodesRequest_encodeBinary(const UA_RegisterNodesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERNODESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterNodesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterNodesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERNODESREQUEST], NULL);
}

/* RegisterNodesResponse */
static UA_INLINE size_t
UA_RegisterNodesResponse_calcSizeBinary(const UA_RegisterNodesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REGISTERNODESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_RegisterNodesResponse_encodeBinary(const UA_RegisterNodesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REGISTERNODESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RegisterNodesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RegisterNodesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REGISTERNODESRESPONSE], NULL);
}

/* UnregisterNodesRequest */
static UA_INLINE size_t
UA_UnregisterNodesRequest_calcSizeBinary(const UA_UnregisterNodesRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UNREGISTERNODESREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_UnregisterNodesRequest_encodeBinary(const UA_UnregisterNodesRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UNREGISTERNODESREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UnregisterNodesRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UnregisterNodesRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UNREGISTERNODESREQUEST], NULL);
}

/* UnregisterNodesResponse */
static UA_INLINE size_t
UA_UnregisterNodesResponse_calcSizeBinary(const UA_UnregisterNodesResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_UNREGISTERNODESRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_UnregisterNodesResponse_encodeBinary(const UA_UnregisterNodesResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_UNREGISTERNODESRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UnregisterNodesResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UnregisterNodesResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_UNREGISTERNODESRESPONSE], NULL);
}

/* FilterOperator */
static UA_INLINE size_t
UA_FilterOperator_calcSizeBinary(const UA_FilterOperator *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FILTEROPERATOR]);
}
static UA_INLINE UA_StatusCode
UA_FilterOperator_encodeBinary(const UA_FilterOperator *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FILTEROPERATOR], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FilterOperator_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FilterOperator *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FILTEROPERATOR], NULL);
}

/* ContentFilterElement */
static UA_INLINE size_t
UA_ContentFilterElement_calcSizeBinary(const UA_ContentFilterElement *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENT]);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterElement_encodeBinary(const UA_ContentFilterElement *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterElement_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ContentFilterElement *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENT], NULL);
}

/* ContentFilter */
static UA_INLINE size_t
UA_ContentFilter_calcSizeBinary(const UA_ContentFilter *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTER]);
}
static UA_INLINE UA_StatusCode
UA_ContentFilter_encodeBinary(const UA_ContentFilter *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ContentFilter_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ContentFilter *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CONTENTFILTER], NULL);
}

/* FilterOperand */
static UA_INLINE size_t
UA_FilterOperand_calcSizeBinary(const UA_FilterOperand *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_FILTEROPERAND]);
}
static UA_INLINE UA_StatusCode
UA_FilterOperand_encodeBinary(const UA_FilterOperand *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_FILTEROPERAND], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_FilterOperand_decodeBinary(const UA_ByteString *src, size_t *offset, UA_FilterOperand *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_FILTEROPERAND], NULL);
}

/* ElementOperand */
static UA_INLINE size_t
UA_ElementOperand_calcSizeBinary(const UA_ElementOperand *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ELEMENTOPERAND]);
}
static UA_INLINE UA_StatusCode
UA_ElementOperand_encodeBinary(const UA_ElementOperand *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ELEMENTOPERAND], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ElementOperand_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ElementOperand *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ELEMENTOPERAND], NULL);
}

/* LiteralOperand */
static UA_INLINE size_t
UA_LiteralOperand_calcSizeBinary(const UA_LiteralOperand *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_LITERALOPERAND]);
}
static UA_INLINE UA_StatusCode
UA_LiteralOperand_encodeBinary(const UA_LiteralOperand *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_LITERALOPERAND], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LiteralOperand_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LiteralOperand *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_LITERALOPERAND], NULL);
}

/* AttributeOperand */
static UA_INLINE size_t
UA_AttributeOperand_calcSizeBinary(const UA_AttributeOperand *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ATTRIBUTEOPERAND]);
}
static UA_INLINE UA_StatusCode
UA_AttributeOperand_encodeBinary(const UA_AttributeOperand *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ATTRIBUTEOPERAND], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AttributeOperand_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AttributeOperand *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ATTRIBUTEOPERAND], NULL);
}

/* SimpleAttributeOperand */
static UA_INLINE size_t
UA_SimpleAttributeOperand_calcSizeBinary(const UA_SimpleAttributeOperand *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SIMPLEATTRIBUTEOPERAND]);
}
static UA_INLINE UA_StatusCode
UA_SimpleAttributeOperand_encodeBinary(const UA_SimpleAttributeOperand *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SIMPLEATTRIBUTEOPERAND], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SimpleAttributeOperand_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SimpleAttributeOperand *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SIMPLEATTRIBUTEOPERAND], NULL);
}

/* ContentFilterElementResult */
static UA_INLINE size_t
UA_ContentFilterElementResult_calcSizeBinary(const UA_ContentFilterElementResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENTRESULT]);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterElementResult_encodeBinary(const UA_ContentFilterElementResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENTRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterElementResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ContentFilterElementResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CONTENTFILTERELEMENTRESULT], NULL);
}

/* ContentFilterResult */
static UA_INLINE size_t
UA_ContentFilterResult_calcSizeBinary(const UA_ContentFilterResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERRESULT]);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterResult_encodeBinary(const UA_ContentFilterResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CONTENTFILTERRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ContentFilterResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ContentFilterResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CONTENTFILTERRESULT], NULL);
}

/* TimestampsToReturn */
static UA_INLINE size_t
UA_TimestampsToReturn_calcSizeBinary(const UA_TimestampsToReturn *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_TIMESTAMPSTORETURN]);
}
static UA_INLINE UA_StatusCode
UA_TimestampsToReturn_encodeBinary(const UA_TimestampsToReturn *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_TIMESTAMPSTORETURN], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TimestampsToReturn_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TimestampsToReturn *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_TIMESTAMPSTORETURN], NULL);
}

/* ReadValueId */
static UA_INLINE size_t
UA_ReadValueId_calcSizeBinary(const UA_ReadValueId *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_READVALUEID]);
}
static UA_INLINE UA_StatusCode
UA_ReadValueId_encodeBinary(const UA_ReadValueId *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_READVALUEID], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ReadValueId_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ReadValueId *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_READVALUEID], NULL);
}

/* ReadRequest */
static UA_INLINE size_t
UA_ReadRequest_calcSizeBinary(const UA_ReadRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_READREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_ReadRequest_encodeBinary(const UA_ReadRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_READREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ReadRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ReadRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_READREQUEST], NULL);
}

/* ReadResponse */
static UA_INLINE size_t
UA_ReadResponse_calcSizeBinary(const UA_ReadResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_READRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_ReadResponse_encodeBinary(const UA_ReadResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_READRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ReadResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ReadResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_READRESPONSE], NULL);
}

/* WriteValue */
static UA_INLINE size_t
UA_WriteValue_calcSizeBinary(const UA_WriteValue *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_WRITEVALUE]);
}
static UA_INLINE UA_StatusCode
UA_WriteValue_encodeBinary(const UA_WriteValue *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_WRITEVALUE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_WriteValue_decodeBinary(const UA_ByteString *src, size_t *offset, UA_WriteValue *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_WRITEVALUE], NULL);
}

/* WriteRequest */
static UA_INLINE size_t
UA_WriteRequest_calcSizeBinary(const UA_WriteRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_WRITEREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_WriteRequest_encodeBinary(const UA_WriteRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_WRITEREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_WriteRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_WriteRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_WRITEREQUEST], NULL);
}

/* WriteResponse */
static UA_INLINE size_t
UA_WriteResponse_calcSizeBinary(const UA_WriteResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_WRITERESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_WriteResponse_encodeBinary(const UA_WriteResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_WRITERESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_WriteResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_WriteResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_WRITERESPONSE], NULL);
}

/* CallMethodRequest */
static UA_INLINE size_t
UA_CallMethodRequest_calcSizeBinary(const UA_CallMethodRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CALLMETHODREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CallMethodRequest_encodeBinary(const UA_CallMethodRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CALLMETHODREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CallMethodRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CallMethodRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CALLMETHODREQUEST], NULL);
}

/* CallMethodResult */
static UA_INLINE size_t
UA_CallMethodResult_calcSizeBinary(const UA_CallMethodResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CALLMETHODRESULT]);
}
static UA_INLINE UA_StatusCode
UA_CallMethodResult_encodeBinary(const UA_CallMethodResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CALLMETHODRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CallMethodResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CallMethodResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CALLMETHODRESULT], NULL);
}

/* CallRequest */
static UA_INLINE size_t
UA_CallRequest_calcSizeBinary(const UA_CallRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CALLREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CallRequest_encodeBinary(const UA_CallRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CALLREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CallRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CallRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CALLREQUEST], NULL);
}

/* CallResponse */
static UA_INLINE size_t
UA_CallResponse_calcSizeBinary(const UA_CallResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CALLRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CallResponse_encodeBinary(const UA_CallResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CALLRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CallResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CallResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CALLRESPONSE], NULL);
}

/* MonitoringMode */
static UA_INLINE size_t
UA_MonitoringMode_calcSizeBinary(const UA_MonitoringMode *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITORINGMODE]);
}
static UA_INLINE UA_StatusCode
UA_MonitoringMode_encodeBinary(const UA_MonitoringMode *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITORINGMODE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoringMode_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoringMode *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITORINGMODE], NULL);
}

/* DataChangeTrigger */
static UA_INLINE size_t
UA_DataChangeTrigger_calcSizeBinary(const UA_DataChangeTrigger *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGETRIGGER]);
}
static UA_INLINE UA_StatusCode
UA_DataChangeTrigger_encodeBinary(const UA_DataChangeTrigger *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGETRIGGER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DataChangeTrigger_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DataChangeTrigger *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATACHANGETRIGGER], NULL);
}

/* DeadbandType */
static UA_INLINE size_t
UA_DeadbandType_calcSizeBinary(const UA_DeadbandType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DEADBANDTYPE]);
}
static UA_INLINE UA_StatusCode
UA_DeadbandType_encodeBinary(const UA_DeadbandType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DEADBANDTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeadbandType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeadbandType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DEADBANDTYPE], NULL);
}

/* DataChangeFilter */
static UA_INLINE size_t
UA_DataChangeFilter_calcSizeBinary(const UA_DataChangeFilter *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGEFILTER]);
}
static UA_INLINE UA_StatusCode
UA_DataChangeFilter_encodeBinary(const UA_DataChangeFilter *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGEFILTER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DataChangeFilter_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DataChangeFilter *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATACHANGEFILTER], NULL);
}

/* EventFilter */
static UA_INLINE size_t
UA_EventFilter_calcSizeBinary(const UA_EventFilter *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EVENTFILTER]);
}
static UA_INLINE UA_StatusCode
UA_EventFilter_encodeBinary(const UA_EventFilter *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EVENTFILTER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EventFilter_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EventFilter *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EVENTFILTER], NULL);
}

/* AggregateConfiguration */
static UA_INLINE size_t
UA_AggregateConfiguration_calcSizeBinary(const UA_AggregateConfiguration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_AGGREGATECONFIGURATION]);
}
static UA_INLINE UA_StatusCode
UA_AggregateConfiguration_encodeBinary(const UA_AggregateConfiguration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_AGGREGATECONFIGURATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AggregateConfiguration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AggregateConfiguration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_AGGREGATECONFIGURATION], NULL);
}

/* AggregateFilter */
static UA_INLINE size_t
UA_AggregateFilter_calcSizeBinary(const UA_AggregateFilter *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_AGGREGATEFILTER]);
}
static UA_INLINE UA_StatusCode
UA_AggregateFilter_encodeBinary(const UA_AggregateFilter *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_AGGREGATEFILTER], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AggregateFilter_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AggregateFilter *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_AGGREGATEFILTER], NULL);
}

/* EventFilterResult */
static UA_INLINE size_t
UA_EventFilterResult_calcSizeBinary(const UA_EventFilterResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EVENTFILTERRESULT]);
}
static UA_INLINE UA_StatusCode
UA_EventFilterResult_encodeBinary(const UA_EventFilterResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EVENTFILTERRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EventFilterResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EventFilterResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EVENTFILTERRESULT], NULL);
}

/* MonitoringParameters */
static UA_INLINE size_t
UA_MonitoringParameters_calcSizeBinary(const UA_MonitoringParameters *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITORINGPARAMETERS]);
}
static UA_INLINE UA_StatusCode
UA_MonitoringParameters_encodeBinary(const UA_MonitoringParameters *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITORINGPARAMETERS], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoringParameters_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoringParameters *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITORINGPARAMETERS], NULL);
}

/* MonitoredItemCreateRequest */
static UA_INLINE size_t
UA_MonitoredItemCreateRequest_calcSizeBinary(const UA_MonitoredItemCreateRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATEREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemCreateRequest_encodeBinary(const UA_MonitoredItemCreateRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATEREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemCreateRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoredItemCreateRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATEREQUEST], NULL);
}

/* MonitoredItemCreateResult */
static UA_INLINE size_t
UA_MonitoredItemCreateResult_calcSizeBinary(const UA_MonitoredItemCreateResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATERESULT]);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemCreateResult_encodeBinary(const UA_MonitoredItemCreateResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATERESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemCreateResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoredItemCreateResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITOREDITEMCREATERESULT], NULL);
}

/* CreateMonitoredItemsRequest */
static UA_INLINE size_t
UA_CreateMonitoredItemsRequest_calcSizeBinary(const UA_CreateMonitoredItemsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CreateMonitoredItemsRequest_encodeBinary(const UA_CreateMonitoredItemsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateMonitoredItemsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateMonitoredItemsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSREQUEST], NULL);
}

/* CreateMonitoredItemsResponse */
static UA_INLINE size_t
UA_CreateMonitoredItemsResponse_calcSizeBinary(const UA_CreateMonitoredItemsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CreateMonitoredItemsResponse_encodeBinary(const UA_CreateMonitoredItemsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateMonitoredItemsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateMonitoredItemsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATEMONITOREDITEMSRESPONSE], NULL);
}

/* MonitoredItemModifyRequest */
static UA_INLINE size_t
UA_MonitoredItemModifyRequest_calcSizeBinary(const UA_MonitoredItemModifyRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemModifyRequest_encodeBinary(const UA_MonitoredItemModifyRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemModifyRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoredItemModifyRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYREQUEST], NULL);
}

/* MonitoredItemModifyResult */
static UA_INLINE size_t
UA_MonitoredItemModifyResult_calcSizeBinary(const UA_MonitoredItemModifyResult *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYRESULT]);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemModifyResult_encodeBinary(const UA_MonitoredItemModifyResult *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYRESULT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemModifyResult_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoredItemModifyResult *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITOREDITEMMODIFYRESULT], NULL);
}

/* ModifyMonitoredItemsRequest */
static UA_INLINE size_t
UA_ModifyMonitoredItemsRequest_calcSizeBinary(const UA_ModifyMonitoredItemsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_ModifyMonitoredItemsRequest_encodeBinary(const UA_ModifyMonitoredItemsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ModifyMonitoredItemsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ModifyMonitoredItemsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSREQUEST], NULL);
}

/* ModifyMonitoredItemsResponse */
static UA_INLINE size_t
UA_ModifyMonitoredItemsResponse_calcSizeBinary(const UA_ModifyMonitoredItemsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_ModifyMonitoredItemsResponse_encodeBinary(const UA_ModifyMonitoredItemsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ModifyMonitoredItemsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ModifyMonitoredItemsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MODIFYMONITOREDITEMSRESPONSE], NULL);
}

/* SetMonitoringModeRequest */
static UA_INLINE size_t
UA_SetMonitoringModeRequest_calcSizeBinary(const UA_SetMonitoringModeRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETMONITORINGMODEREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_SetMonitoringModeRequest_encodeBinary(const UA_SetMonitoringModeRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETMONITORINGMODEREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetMonitoringModeRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetMonitoringModeRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETMONITORINGMODEREQUEST], NULL);
}

/* SetMonitoringModeResponse */
static UA_INLINE size_t
UA_SetMonitoringModeResponse_calcSizeBinary(const UA_SetMonitoringModeResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETMONITORINGMODERESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_SetMonitoringModeResponse_encodeBinary(const UA_SetMonitoringModeResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETMONITORINGMODERESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetMonitoringModeResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetMonitoringModeResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETMONITORINGMODERESPONSE], NULL);
}

/* SetTriggeringRequest */
static UA_INLINE size_t
UA_SetTriggeringRequest_calcSizeBinary(const UA_SetTriggeringRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETTRIGGERINGREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_SetTriggeringRequest_encodeBinary(const UA_SetTriggeringRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETTRIGGERINGREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetTriggeringRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetTriggeringRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETTRIGGERINGREQUEST], NULL);
}

/* SetTriggeringResponse */
static UA_INLINE size_t
UA_SetTriggeringResponse_calcSizeBinary(const UA_SetTriggeringResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETTRIGGERINGRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_SetTriggeringResponse_encodeBinary(const UA_SetTriggeringResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETTRIGGERINGRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetTriggeringResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetTriggeringResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETTRIGGERINGRESPONSE], NULL);
}

/* DeleteMonitoredItemsRequest */
static UA_INLINE size_t
UA_DeleteMonitoredItemsRequest_calcSizeBinary(const UA_DeleteMonitoredItemsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_DeleteMonitoredItemsRequest_encodeBinary(const UA_DeleteMonitoredItemsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteMonitoredItemsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteMonitoredItemsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSREQUEST], NULL);
}

/* DeleteMonitoredItemsResponse */
static UA_INLINE size_t
UA_DeleteMonitoredItemsResponse_calcSizeBinary(const UA_DeleteMonitoredItemsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_DeleteMonitoredItemsResponse_encodeBinary(const UA_DeleteMonitoredItemsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteMonitoredItemsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteMonitoredItemsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETEMONITOREDITEMSRESPONSE], NULL);
}

/* CreateSubscriptionRequest */
static UA_INLINE size_t
UA_CreateSubscriptionRequest_calcSizeBinary(const UA_CreateSubscriptionRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_CreateSubscriptionRequest_encodeBinary(const UA_CreateSubscriptionRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateSubscriptionRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateSubscriptionRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONREQUEST], NULL);
}

/* CreateSubscriptionResponse */
static UA_INLINE size_t
UA_CreateSubscriptionResponse_calcSizeBinary(const UA_CreateSubscriptionResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_CreateSubscriptionResponse_encodeBinary(const UA_CreateSubscriptionResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CreateSubscriptionResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CreateSubscriptionResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_CREATESUBSCRIPTIONRESPONSE], NULL);
}

/* ModifySubscriptionRequest */
static UA_INLINE size_t
UA_ModifySubscriptionRequest_calcSizeBinary(const UA_ModifySubscriptionRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_ModifySubscriptionRequest_encodeBinary(const UA_ModifySubscriptionRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ModifySubscriptionRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ModifySubscriptionRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONREQUEST], NULL);
}

/* ModifySubscriptionResponse */
static UA_INLINE size_t
UA_ModifySubscriptionResponse_calcSizeBinary(const UA_ModifySubscriptionResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_ModifySubscriptionResponse_encodeBinary(const UA_ModifySubscriptionResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ModifySubscriptionResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ModifySubscriptionResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MODIFYSUBSCRIPTIONRESPONSE], NULL);
}

/* SetPublishingModeRequest */
static UA_INLINE size_t
UA_SetPublishingModeRequest_calcSizeBinary(const UA_SetPublishingModeRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODEREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_SetPublishingModeRequest_encodeBinary(const UA_SetPublishingModeRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODEREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetPublishingModeRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetPublishingModeRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODEREQUEST], NULL);
}

/* SetPublishingModeResponse */
static UA_INLINE size_t
UA_SetPublishingModeResponse_calcSizeBinary(const UA_SetPublishingModeResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODERESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_SetPublishingModeResponse_encodeBinary(const UA_SetPublishingModeResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODERESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SetPublishingModeResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SetPublishingModeResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SETPUBLISHINGMODERESPONSE], NULL);
}

/* NotificationMessage */
static UA_INLINE size_t
UA_NotificationMessage_calcSizeBinary(const UA_NotificationMessage *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_NOTIFICATIONMESSAGE]);
}
static UA_INLINE UA_StatusCode
UA_NotificationMessage_encodeBinary(const UA_NotificationMessage *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_NOTIFICATIONMESSAGE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NotificationMessage_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NotificationMessage *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_NOTIFICATIONMESSAGE], NULL);
}

/* MonitoredItemNotification */
static UA_INLINE size_t
UA_MonitoredItemNotification_calcSizeBinary(const UA_MonitoredItemNotification *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMNOTIFICATION]);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemNotification_encodeBinary(const UA_MonitoredItemNotification *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_MONITOREDITEMNOTIFICATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MonitoredItemNotification_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MonitoredItemNotification *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_MONITOREDITEMNOTIFICATION], NULL);
}

/* EventFieldList */
static UA_INLINE size_t
UA_EventFieldList_calcSizeBinary(const UA_EventFieldList *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EVENTFIELDLIST]);
}
static UA_INLINE UA_StatusCode
UA_EventFieldList_encodeBinary(const UA_EventFieldList *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EVENTFIELDLIST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EventFieldList_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EventFieldList *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EVENTFIELDLIST], NULL);
}

/* StatusChangeNotification */
static UA_INLINE size_t
UA_StatusChangeNotification_calcSizeBinary(const UA_StatusChangeNotification *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_STATUSCHANGENOTIFICATION]);
}
static UA_INLINE UA_StatusCode
UA_StatusChangeNotification_encodeBinary(const UA_StatusChangeNotification *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_STATUSCHANGENOTIFICATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StatusChangeNotification_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StatusChangeNotification *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_STATUSCHANGENOTIFICATION], NULL);
}

/* SubscriptionAcknowledgement */
static UA_INLINE size_t
UA_SubscriptionAcknowledgement_calcSizeBinary(const UA_SubscriptionAcknowledgement *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SUBSCRIPTIONACKNOWLEDGEMENT]);
}
static UA_INLINE UA_StatusCode
UA_SubscriptionAcknowledgement_encodeBinary(const UA_SubscriptionAcknowledgement *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SUBSCRIPTIONACKNOWLEDGEMENT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SubscriptionAcknowledgement_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SubscriptionAcknowledgement *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SUBSCRIPTIONACKNOWLEDGEMENT], NULL);
}

/* PublishRequest */
static UA_INLINE size_t
UA_PublishRequest_calcSizeBinary(const UA_PublishRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_PUBLISHREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_PublishRequest_encodeBinary(const UA_PublishRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_PUBLISHREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_PublishRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_PublishRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_PUBLISHREQUEST], NULL);
}

/* PublishResponse */
static UA_INLINE size_t
UA_PublishResponse_calcSizeBinary(const UA_PublishResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_PUBLISHRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_PublishResponse_encodeBinary(const UA_PublishResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_PUBLISHRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_PublishResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_PublishResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_PUBLISHRESPONSE], NULL);
}

/* RepublishRequest */
static UA_INLINE size_t
UA_RepublishRequest_calcSizeBinary(const UA_RepublishRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REPUBLISHREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_RepublishRequest_encodeBinary(const UA_RepublishRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REPUBLISHREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RepublishRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RepublishRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REPUBLISHREQUEST], NULL);
}

/* RepublishResponse */
static UA_INLINE size_t
UA_RepublishResponse_calcSizeBinary(const UA_RepublishResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REPUBLISHRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_RepublishResponse_encodeBinary(const UA_RepublishResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REPUBLISHRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RepublishResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RepublishResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REPUBLISHRESPONSE], NULL);
}

/* DeleteSubscriptionsRequest */
static UA_INLINE size_t
UA_DeleteSubscriptionsRequest_calcSizeBinary(const UA_DeleteSubscriptionsRequest *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSREQUEST]);
}
static UA_INLINE UA_StatusCode
UA_DeleteSubscriptionsRequest_encodeBinary(const UA_DeleteSubscriptionsRequest *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSREQUEST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteSubscriptionsRequest_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteSubscriptionsRequest *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSREQUEST], NULL);
}

/* DeleteSubscriptionsResponse */
static UA_INLINE size_t
UA_DeleteSubscriptionsResponse_calcSizeBinary(const UA_DeleteSubscriptionsResponse *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSRESPONSE]);
}
static UA_INLINE UA_StatusCode
UA_DeleteSubscriptionsResponse_encodeBinary(const UA_DeleteSubscriptionsResponse *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSRESPONSE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DeleteSubscriptionsResponse_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DeleteSubscriptionsResponse *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DELETESUBSCRIPTIONSRESPONSE], NULL);
}

/* BuildInfo */
static UA_INLINE size_t
UA_BuildInfo_calcSizeBinary(const UA_BuildInfo *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_BUILDINFO]);
}
static UA_INLINE UA_StatusCode
UA_BuildInfo_encodeBinary(const UA_BuildInfo *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_BUILDINFO], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_BuildInfo_decodeBinary(const UA_ByteString *src, size_t *offset, UA_BuildInfo *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_BUILDINFO], NULL);
}

/* RedundancySupport */
static UA_INLINE size_t
UA_RedundancySupport_calcSizeBinary(const UA_RedundancySupport *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_REDUNDANCYSUPPORT]);
}
static UA_INLINE UA_StatusCode
UA_RedundancySupport_encodeBinary(const UA_RedundancySupport *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_REDUNDANCYSUPPORT], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_RedundancySupport_decodeBinary(const UA_ByteString *src, size_t *offset, UA_RedundancySupport *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_REDUNDANCYSUPPORT], NULL);
}

/* ServerState */
static UA_INLINE size_t
UA_ServerState_calcSizeBinary(const UA_ServerState *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SERVERSTATE]);
}
static UA_INLINE UA_StatusCode
UA_ServerState_encodeBinary(const UA_ServerState *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SERVERSTATE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ServerState_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ServerState *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SERVERSTATE], NULL);
}

/* ServerDiagnosticsSummaryDataType */
static UA_INLINE size_t
UA_ServerDiagnosticsSummaryDataType_calcSizeBinary(const UA_ServerDiagnosticsSummaryDataType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SERVERDIAGNOSTICSSUMMARYDATATYPE]);
}
static UA_INLINE UA_StatusCode
UA_ServerDiagnosticsSummaryDataType_encodeBinary(const UA_ServerDiagnosticsSummaryDataType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SERVERDIAGNOSTICSSUMMARYDATATYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ServerDiagnosticsSummaryDataType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ServerDiagnosticsSummaryDataType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SERVERDIAGNOSTICSSUMMARYDATATYPE], NULL);
}

/* ServerStatusDataType */
static UA_INLINE size_t
UA_ServerStatusDataType_calcSizeBinary(const UA_ServerStatusDataType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_SERVERSTATUSDATATYPE]);
}
static UA_INLINE UA_StatusCode
UA_ServerStatusDataType_encodeBinary(const UA_ServerStatusDataType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_SERVERSTATUSDATATYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ServerStatusDataType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ServerStatusDataType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_SERVERSTATUSDATATYPE], NULL);
}

/* Range */
static UA_INLINE size_t
UA_Range_calcSizeBinary(const UA_Range *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_RANGE]);
}
static UA_INLINE UA_StatusCode
UA_Range_encodeBinary(const UA_Range *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_RANGE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_Range_decodeBinary(const UA_ByteString *src, size_t *offset, UA_Range *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_RANGE], NULL);
}

/* EUInformation */
static UA_INLINE size_t
UA_EUInformation_calcSizeBinary(const UA_EUInformation *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EUINFORMATION]);
}
static UA_INLINE UA_StatusCode
UA_EUInformation_encodeBinary(const UA_EUInformation *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EUINFORMATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EUInformation_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EUInformation *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EUINFORMATION], NULL);
}

/* AxisScaleEnumeration */
static UA_INLINE size_t
UA_AxisScaleEnumeration_calcSizeBinary(const UA_AxisScaleEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_AXISSCALEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_AxisScaleEnumeration_encodeBinary(const UA_AxisScaleEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_AXISSCALEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AxisScaleEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AxisScaleEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_AXISSCALEENUMERATION], NULL);
}

/* ComplexNumberType */
static UA_INLINE size_t
UA_ComplexNumberType_calcSizeBinary(const UA_ComplexNumberType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_COMPLEXNUMBERTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ComplexNumberType_encodeBinary(const UA_ComplexNumberType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_COMPLEXNUMBERTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ComplexNumberType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ComplexNumberType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_COMPLEXNUMBERTYPE], NULL);
}

/* DoubleComplexNumberType */
static UA_INLINE size_t
UA_DoubleComplexNumberType_calcSizeBinary(const UA_DoubleComplexNumberType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DOUBLECOMPLEXNUMBERTYPE]);
}
static UA_INLINE UA_StatusCode
UA_DoubleComplexNumberType_encodeBinary(const UA_DoubleComplexNumberType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DOUBLECOMPLEXNUMBERTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DoubleComplexNumberType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DoubleComplexNumberType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DOUBLECOMPLEXNUMBERTYPE], NULL);
}

/* AxisInformation */
static UA_INLINE size_t
UA_AxisInformation_calcSizeBinary(const UA_AxisInformation *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_AXISINFORMATION]);
}
static UA_INLINE UA_StatusCode
UA_AxisInformation_encodeBinary(const UA_AxisInformation *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_AXISINFORMATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_AxisInformation_decodeBinary(const UA_ByteString *src, size_t *offset, UA_AxisInformation *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_AXISINFORMATION], NULL);
}

/* XVType */
static UA_INLINE size_t
UA_XVType_calcSizeBinary(const UA_XVType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_XVTYPE]);
}
static UA_INLINE UA_StatusCode
UA_XVType_encodeBinary(const UA_XVType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_XVTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_XVType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_XVType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_XVTYPE], NULL);
}

/* EnumDefinition */
static UA_INLINE size_t
UA_EnumDefinition_calcSizeBinary(const UA_EnumDefinition *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_ENUMDEFINITION]);
}
static UA_INLINE UA_StatusCode
UA_EnumDefinition_encodeBinary(const UA_EnumDefinition *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_ENUMDEFINITION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EnumDefinition_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EnumDefinition *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_ENUMDEFINITION], NULL);
}

/* DataChangeNotification */
static UA_INLINE size_t
UA_DataChangeNotification_calcSizeBinary(const UA_DataChangeNotification *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGENOTIFICATION]);
}
static UA_INLINE UA_StatusCode
UA_DataChangeNotification_encodeBinary(const UA_DataChangeNotification *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_DATACHANGENOTIFICATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_DataChangeNotification_decodeBinary(const UA_ByteString *src, size_t *offset, UA_DataChangeNotification *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_DATACHANGENOTIFICATION], NULL);
}

/* EventNotificationList */
static UA_INLINE size_t
UA_EventNotificationList_calcSizeBinary(const UA_EventNotificationList *src) {
    return UA_calcSizeBinary(src, &UA_TYPES[UA_TYPES_EVENTNOTIFICATIONLIST]);
}
static UA_INLINE UA_StatusCode
UA_EventNotificationList_encodeBinary(const UA_EventNotificationList *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES[UA_TYPES_EVENTNOTIFICATIONLIST], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EventNotificationList_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EventNotificationList *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES[UA_TYPES_EVENTNOTIFICATIONLIST], NULL);
}

#endif /* TYPES_GENERATED_ENCODING_BINARY_H_ */
