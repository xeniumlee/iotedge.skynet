/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "namespace0_generated.h"


/* HasAddIn - ns=0;i=17604 */

static UA_StatusCode function_namespace0_generated_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "AddInOf");
attr.displayName = UA_LOCALIZEDTEXT("", "HasAddIn");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 17604),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "HasAddIn"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 17604)
);
}

/* HasInterface - ns=0;i=17603 */

static UA_StatusCode function_namespace0_generated_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "InterfaceOf");
attr.displayName = UA_LOCALIZEDTEXT("", "HasInterface");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 17603),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "HasInterface"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 17603)
);
}

/* HasHistoricalConfiguration - ns=0;i=56 */

static UA_StatusCode function_namespace0_generated_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "HistoricalConfigurationOf");
attr.displayName = UA_LOCALIZEDTEXT("", "HasHistoricalConfiguration");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 56),
UA_NODEID_NUMERIC(ns[0], 44),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "HasHistoricalConfiguration"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 56)
);
}

/* HasEffect - ns=0;i=54 */

static UA_StatusCode function_namespace0_generated_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "MayBeEffectedBy");
attr.displayName = UA_LOCALIZEDTEXT("", "HasEffect");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 54),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "HasEffect"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 54)
);
}

/* HasCause - ns=0;i=53 */

static UA_StatusCode function_namespace0_generated_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "MayBeCausedBy");
attr.displayName = UA_LOCALIZEDTEXT("", "HasCause");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 53),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "HasCause"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 53)
);
}

/* ToState - ns=0;i=52 */

static UA_StatusCode function_namespace0_generated_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "FromTransition");
attr.displayName = UA_LOCALIZEDTEXT("", "ToState");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 52),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ToState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 52)
);
}

/* FromState - ns=0;i=51 */

static UA_StatusCode function_namespace0_generated_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ReferenceTypeAttributes attr = UA_ReferenceTypeAttributes_default;
attr.inverseName  = UA_LOCALIZEDTEXT("", "ToTransition");
attr.displayName = UA_LOCALIZEDTEXT("", "FromState");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_REFERENCETYPE,
UA_NODEID_NUMERIC(ns[0], 51),
UA_NODEID_NUMERIC(ns[0], 32),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "FromState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_REFERENCETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 51)
);
}

/* DiagnosticInfo - ns=0;i=25 */

static UA_StatusCode function_namespace0_generated_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DiagnosticInfo");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 25),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DiagnosticInfo"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 25)
);
}

/* DataValue - ns=0;i=23 */

static UA_StatusCode function_namespace0_generated_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DataValue");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 23),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DataValue"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 23)
);
}

/* Structure - ns=0;i=22 */

static UA_StatusCode function_namespace0_generated_9_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Structure");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Structure"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 22)
);
}

/* EnumValueType - ns=0;i=7594 */

static UA_StatusCode function_namespace0_generated_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "EnumValueType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 7594),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "EnumValueType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7594)
);
}

/* BuildInfo - ns=0;i=338 */

static UA_StatusCode function_namespace0_generated_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "BuildInfo");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 338),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "BuildInfo"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 338)
);
}

/* Argument - ns=0;i=296 */

static UA_StatusCode function_namespace0_generated_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Argument");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 296),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Argument"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 296)
);
}

/* ServerDiagnosticsSummaryDataType - ns=0;i=859 */

static UA_StatusCode function_namespace0_generated_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerDiagnosticsSummaryDataType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 859),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerDiagnosticsSummaryDataType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 859)
);
}

/* ServerStatusDataType - ns=0;i=862 */

static UA_StatusCode function_namespace0_generated_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerStatusDataType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 862),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerStatusDataType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 862)
);
}

/* SignedSoftwareCertificate - ns=0;i=344 */

static UA_StatusCode function_namespace0_generated_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SignedSoftwareCertificate");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 344),
UA_NODEID_NUMERIC(ns[0], 22),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "SignedSoftwareCertificate"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 344)
);
}

/* LocalizedText - ns=0;i=21 */

static UA_StatusCode function_namespace0_generated_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "LocalizedText");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 21),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "LocalizedText"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 21)
);
}

/* QualifiedName - ns=0;i=20 */

static UA_StatusCode function_namespace0_generated_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "QualifiedName");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 20),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "QualifiedName"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 20)
);
}

/* StatusCode - ns=0;i=19 */

static UA_StatusCode function_namespace0_generated_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "StatusCode");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 19),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "StatusCode"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 19)
);
}

/* ExpandedNodeId - ns=0;i=18 */

static UA_StatusCode function_namespace0_generated_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ExpandedNodeId");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 18),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ExpandedNodeId"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 18)
);
}

/* NodeId - ns=0;i=17 */

static UA_StatusCode function_namespace0_generated_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "NodeId");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 17),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "NodeId"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 17)
);
}

/* XmlElement - ns=0;i=16 */

static UA_StatusCode function_namespace0_generated_21_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "XmlElement");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 16),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "XmlElement"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 16)
);
}

/* ByteString - ns=0;i=15 */

static UA_StatusCode function_namespace0_generated_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ByteString");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 15),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ByteString"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 15)
);
}

/* Image - ns=0;i=30 */

static UA_StatusCode function_namespace0_generated_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Image");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 30),
UA_NODEID_NUMERIC(ns[0], 15),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Image"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 30)
);
}

/* Guid - ns=0;i=14 */

static UA_StatusCode function_namespace0_generated_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Guid");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 14),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Guid"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 14)
);
}

/* DateTime - ns=0;i=13 */

static UA_StatusCode function_namespace0_generated_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DateTime");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 13),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DateTime"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 13)
);
}

/* UtcTime - ns=0;i=294 */

static UA_StatusCode function_namespace0_generated_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "UtcTime");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 294),
UA_NODEID_NUMERIC(ns[0], 13),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "UtcTime"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 294)
);
}

/* String - ns=0;i=12 */

static UA_StatusCode function_namespace0_generated_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "String");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 12),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "String"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 12)
);
}

/* LocaleId - ns=0;i=295 */

static UA_StatusCode function_namespace0_generated_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "LocaleId");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 295),
UA_NODEID_NUMERIC(ns[0], 12),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "LocaleId"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 295)
);
}

/* Boolean - ns=0;i=1 */

static UA_StatusCode function_namespace0_generated_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Boolean");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 1),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Boolean"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 1)
);
}

/* Enumeration - ns=0;i=29 */

static UA_StatusCode function_namespace0_generated_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Enumeration");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 29),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Enumeration"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 29)
);
}

/* ServerState - ns=0;i=852 */

static UA_StatusCode function_namespace0_generated_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerState");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 852),
UA_NODEID_NUMERIC(ns[0], 29),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerState"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 852)
);
}

/* NamingRuleType - ns=0;i=120 */

static UA_StatusCode function_namespace0_generated_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "NamingRuleType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 120),
UA_NODEID_NUMERIC(ns[0], 29),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "NamingRuleType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 120)
);
}

/* EnumValues - ns=0;i=12169 */

static UA_StatusCode function_namespace0_generated_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7594);
UA_EnumValueType variablenode_ns_0_i_12169_variant_DataContents[3];

UA_init(&variablenode_ns_0_i_12169_variant_DataContents[0], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_0_i_12169_variant_DataContents[0].value = (UA_Int64) 1;
variablenode_ns_0_i_12169_variant_DataContents[0].displayName = UA_LOCALIZEDTEXT("", "Mandatory");
variablenode_ns_0_i_12169_variant_DataContents[0].description = UA_LOCALIZEDTEXT("", "The BrowseName must appear in all instances of the type.");

UA_init(&variablenode_ns_0_i_12169_variant_DataContents[1], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_0_i_12169_variant_DataContents[1].value = (UA_Int64) 2;
variablenode_ns_0_i_12169_variant_DataContents[1].displayName = UA_LOCALIZEDTEXT("", "Optional");
variablenode_ns_0_i_12169_variant_DataContents[1].description = UA_LOCALIZEDTEXT("", "The BrowseName may appear in an instance of the type.");

UA_init(&variablenode_ns_0_i_12169_variant_DataContents[2], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_0_i_12169_variant_DataContents[2].value = (UA_Int64) 3;
variablenode_ns_0_i_12169_variant_DataContents[2].displayName = UA_LOCALIZEDTEXT("", "Constraint");
variablenode_ns_0_i_12169_variant_DataContents[2].description = UA_LOCALIZEDTEXT("", "The modelling rule defines a constraint and the BrowseName is not used in an instance of the type.");
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_12169_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumValues");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 12169),
UA_NODEID_NUMERIC(ns[0], 120),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EnumValues"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



return retVal;
}

static UA_StatusCode function_namespace0_generated_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 12169)
);
}

/* RedundancySupport - ns=0;i=851 */

static UA_StatusCode function_namespace0_generated_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RedundancySupport");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 851),
UA_NODEID_NUMERIC(ns[0], 29),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "RedundancySupport"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 851)
);
}

/* EnumStrings - ns=0;i=7611 */

static UA_StatusCode function_namespace0_generated_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 21);
UA_LocalizedText variablenode_ns_0_i_7611_variant_DataContents[6];
variablenode_ns_0_i_7611_variant_DataContents[0] = UA_LOCALIZEDTEXT("", "None");
variablenode_ns_0_i_7611_variant_DataContents[1] = UA_LOCALIZEDTEXT("", "Cold");
variablenode_ns_0_i_7611_variant_DataContents[2] = UA_LOCALIZEDTEXT("", "Warm");
variablenode_ns_0_i_7611_variant_DataContents[3] = UA_LOCALIZEDTEXT("", "Hot");
variablenode_ns_0_i_7611_variant_DataContents[4] = UA_LOCALIZEDTEXT("", "Transparent");
variablenode_ns_0_i_7611_variant_DataContents[5] = UA_LOCALIZEDTEXT("", "HotAndMirrored");
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_7611_variant_DataContents, (UA_Int32) 6, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumStrings");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 7611),
UA_NODEID_NUMERIC(ns[0], 851),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EnumStrings"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7611)
);
}

/* Number - ns=0;i=26 */

static UA_StatusCode function_namespace0_generated_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Number");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 24),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Number"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 26)
);
}

/* Double - ns=0;i=11 */

static UA_StatusCode function_namespace0_generated_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Double");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 11),
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Double"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11)
);
}

/* Duration - ns=0;i=290 */

static UA_StatusCode function_namespace0_generated_38_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Duration");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 290),
UA_NODEID_NUMERIC(ns[0], 11),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Duration"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 290)
);
}

/* Integer - ns=0;i=27 */

static UA_StatusCode function_namespace0_generated_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Integer");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 27),
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Integer"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 27)
);
}

/* Int32 - ns=0;i=6 */

static UA_StatusCode function_namespace0_generated_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Int32");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 6),
UA_NODEID_NUMERIC(ns[0], 27),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Int32"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 6)
);
}

/* Int64 - ns=0;i=8 */

static UA_StatusCode function_namespace0_generated_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Int64");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 8),
UA_NODEID_NUMERIC(ns[0], 27),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Int64"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 8)
);
}

/* Int16 - ns=0;i=4 */

static UA_StatusCode function_namespace0_generated_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Int16");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 4),
UA_NODEID_NUMERIC(ns[0], 27),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Int16"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 4)
);
}

/* SByte - ns=0;i=2 */

static UA_StatusCode function_namespace0_generated_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "SByte");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 2),
UA_NODEID_NUMERIC(ns[0], 27),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "SByte"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2)
);
}

/* Decimal - ns=0;i=50 */

static UA_StatusCode function_namespace0_generated_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Decimal");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 50),
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Decimal"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 50)
);
}

/* Float - ns=0;i=10 */

static UA_StatusCode function_namespace0_generated_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Float");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 10),
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Float"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 10)
);
}

/* UInteger - ns=0;i=28 */

static UA_StatusCode function_namespace0_generated_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "UInteger");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 28),
UA_NODEID_NUMERIC(ns[0], 26),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "UInteger"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 28)
);
}

/* Byte - ns=0;i=3 */

static UA_StatusCode function_namespace0_generated_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Byte");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 3),
UA_NODEID_NUMERIC(ns[0], 28),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "Byte"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3)
);
}

/* UInt32 - ns=0;i=7 */

static UA_StatusCode function_namespace0_generated_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "UInt32");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 7),
UA_NODEID_NUMERIC(ns[0], 28),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "UInt32"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7)
);
}

/* UInt16 - ns=0;i=5 */

static UA_StatusCode function_namespace0_generated_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "UInt16");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 5),
UA_NODEID_NUMERIC(ns[0], 28),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "UInt16"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 5)
);
}

/* UInt64 - ns=0;i=9 */

static UA_StatusCode function_namespace0_generated_50_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "UInt64");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[0], 9),
UA_NODEID_NUMERIC(ns[0], 28),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "UInt64"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 9)
);
}

/* InterfaceTypes - ns=0;i=17708 */

static UA_StatusCode function_namespace0_generated_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InterfaceTypes");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 17708),
UA_NODEID_NUMERIC(ns[0], 86),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "InterfaceTypes"),
UA_NODEID_NUMERIC(ns[0], 61),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 17708)
);
}

/* BaseInterfaceType - ns=0;i=17602 */

static UA_StatusCode function_namespace0_generated_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "BaseInterfaceType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 17602),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "BaseInterfaceType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 17602), UA_NODEID_NUMERIC(ns[0], 35), UA_EXPANDEDNODEID_NUMERIC(ns[0], 17708), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 17602)
);
}

/* ServerDiagnosticsSummaryType - ns=0;i=2150 */

static UA_StatusCode function_namespace0_generated_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableTypeAttributes attr = UA_VariableTypeAttributes_default;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 859);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerDiagnosticsSummaryType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLETYPE,
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 63),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerDiagnosticsSummaryType"),
UA_NODEID_NUMERIC(ns[0], 0),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2150)
);
}

/* SecurityRejectedRequestsCount - ns=0;i=2162 */

static UA_StatusCode function_namespace0_generated_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SecurityRejectedRequestsCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2162),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SecurityRejectedRequestsCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2162)
);
}

/* CurrentSessionCount - ns=0;i=2152 */

static UA_StatusCode function_namespace0_generated_55_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2152),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CurrentSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2152)
);
}

/* CumulatedSessionCount - ns=0;i=2153 */

static UA_StatusCode function_namespace0_generated_56_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CumulatedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2153),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CumulatedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2153)
);
}

/* SecurityRejectedSessionCount - ns=0;i=2154 */

static UA_StatusCode function_namespace0_generated_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SecurityRejectedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2154),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SecurityRejectedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2154)
);
}

/* CumulatedSubscriptionCount - ns=0;i=2161 */

static UA_StatusCode function_namespace0_generated_58_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CumulatedSubscriptionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2161),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CumulatedSubscriptionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_58_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2161)
);
}

/* RejectedSessionCount - ns=0;i=2155 */

static UA_StatusCode function_namespace0_generated_59_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "RejectedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2155),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "RejectedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2155)
);
}

/* RejectedRequestsCount - ns=0;i=2163 */

static UA_StatusCode function_namespace0_generated_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "RejectedRequestsCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2163),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "RejectedRequestsCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2163)
);
}

/* CurrentSubscriptionCount - ns=0;i=2160 */

static UA_StatusCode function_namespace0_generated_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentSubscriptionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2160),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CurrentSubscriptionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2160)
);
}

/* ServerViewCount - ns=0;i=2151 */

static UA_StatusCode function_namespace0_generated_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerViewCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2151),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerViewCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2151)
);
}

/* SessionAbortCount - ns=0;i=2157 */

static UA_StatusCode function_namespace0_generated_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SessionAbortCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2157),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SessionAbortCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2157)
);
}

/* PublishingIntervalCount - ns=0;i=2159 */

static UA_StatusCode function_namespace0_generated_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "PublishingIntervalCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2159),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "PublishingIntervalCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2159)
);
}

/* SessionTimeoutCount - ns=0;i=2156 */

static UA_StatusCode function_namespace0_generated_65_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SessionTimeoutCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2156),
UA_NODEID_NUMERIC(ns[0], 2150),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SessionTimeoutCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_65_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2156)
);
}

/* BuildInfoType - ns=0;i=3051 */

static UA_StatusCode function_namespace0_generated_66_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableTypeAttributes attr = UA_VariableTypeAttributes_default;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 338);
attr.displayName = UA_LOCALIZEDTEXT("", "BuildInfoType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLETYPE,
UA_NODEID_NUMERIC(ns[0], 3051),
UA_NODEID_NUMERIC(ns[0], 63),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "BuildInfoType"),
UA_NODEID_NUMERIC(ns[0], 0),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_66_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3051)
);
}

/* ServerStatusType - ns=0;i=2138 */

static UA_StatusCode function_namespace0_generated_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableTypeAttributes attr = UA_VariableTypeAttributes_default;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 862);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerStatusType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLETYPE,
UA_NODEID_NUMERIC(ns[0], 2138),
UA_NODEID_NUMERIC(ns[0], 63),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerStatusType"),
UA_NODEID_NUMERIC(ns[0], 0),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2138)
);
}

/* OperationLimitsType - ns=0;i=11564 */

static UA_StatusCode function_namespace0_generated_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "OperationLimitsType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 61),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "OperationLimitsType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11564)
);
}

/* MaxNodesPerNodeManagement - ns=0;i=11573 */

static UA_StatusCode function_namespace0_generated_69_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerNodeManagement");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11573),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerNodeManagement"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_69_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11573)
);
}

/* MaxNodesPerRead - ns=0;i=11565 */

static UA_StatusCode function_namespace0_generated_70_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerRead");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11565),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerRead"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_70_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11565)
);
}

/* MaxNodesPerMethodCall - ns=0;i=11569 */

static UA_StatusCode function_namespace0_generated_71_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerMethodCall");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11569),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerMethodCall"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11569)
);
}

/* MaxNodesPerRegisterNodes - ns=0;i=11571 */

static UA_StatusCode function_namespace0_generated_72_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerRegisterNodes");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11571),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerRegisterNodes"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_72_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11571)
);
}

/* MaxNodesPerTranslateBrowsePathsToNodeIds - ns=0;i=11572 */

static UA_StatusCode function_namespace0_generated_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerTranslateBrowsePathsToNodeIds");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11572),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerTranslateBrowsePathsToNodeIds"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11572)
);
}

/* MaxMonitoredItemsPerCall - ns=0;i=11574 */

static UA_StatusCode function_namespace0_generated_74_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxMonitoredItemsPerCall");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11574),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxMonitoredItemsPerCall"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_74_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11574)
);
}

/* MaxNodesPerBrowse - ns=0;i=11570 */

static UA_StatusCode function_namespace0_generated_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerBrowse");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11570),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerBrowse"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11570)
);
}

/* MaxNodesPerWrite - ns=0;i=11567 */

static UA_StatusCode function_namespace0_generated_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerWrite");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11567),
UA_NODEID_NUMERIC(ns[0], 11564),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerWrite"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11567)
);
}

/* ServerRedundancyType - ns=0;i=2034 */

static UA_StatusCode function_namespace0_generated_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerRedundancyType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 2034),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerRedundancyType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2034)
);
}

/* RedundancySupport - ns=0;i=2035 */

static UA_StatusCode function_namespace0_generated_78_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 851);
attr.displayName = UA_LOCALIZEDTEXT("", "RedundancySupport");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2035),
UA_NODEID_NUMERIC(ns[0], 2034),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "RedundancySupport"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_78_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2035)
);
}

/* VendorServerInfoType - ns=0;i=2033 */

static UA_StatusCode function_namespace0_generated_79_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "VendorServerInfoType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 2033),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "VendorServerInfoType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_79_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2033)
);
}

/* ServerDiagnosticsType - ns=0;i=2020 */

static UA_StatusCode function_namespace0_generated_80_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerDiagnosticsType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 2020),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerDiagnosticsType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_80_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2020)
);
}

/* ServerCapabilitiesType - ns=0;i=2013 */

static UA_StatusCode function_namespace0_generated_81_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerCapabilitiesType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 2013),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerCapabilitiesType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_81_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2013)
);
}

/* OperationLimits - ns=0;i=11551 */

static UA_StatusCode function_namespace0_generated_82_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "OperationLimits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 11551),
UA_NODEID_NUMERIC(ns[0], 2013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "OperationLimits"),
UA_NODEID_NUMERIC(ns[0], 11564),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_82_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11551)
);
}

/* ServerType - ns=0;i=2004 */

static UA_StatusCode function_namespace0_generated_83_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 2004),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ServerType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_83_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2004)
);
}

/* Server - ns=0;i=2253 */

static UA_StatusCode function_namespace0_generated_84_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.eventNotifier = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Server");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 85),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "Server"),
UA_NODEID_NUMERIC(ns[0], 2004),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_84_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2253)
);
}

/* Auditing - ns=0;i=2994 */

static UA_StatusCode function_namespace0_generated_85_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
attr.displayName = UA_LOCALIZEDTEXT("", "Auditing");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2994),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Auditing"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_85_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2994)
);
}

/* ServiceLevel - ns=0;i=2267 */

static UA_StatusCode function_namespace0_generated_86_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 3);
attr.displayName = UA_LOCALIZEDTEXT("", "ServiceLevel");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2267),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "ServiceLevel"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_86_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2267)
);
}

/* ServerArray - ns=0;i=2254 */

static UA_StatusCode function_namespace0_generated_87_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerArray");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2254),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "ServerArray"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_87_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2254)
);
}

/* ServerRedundancy - ns=0;i=2296 */

static UA_StatusCode function_namespace0_generated_88_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerRedundancy");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2296),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerRedundancy"),
UA_NODEID_NUMERIC(ns[0], 2034),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_88_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2296)
);
}

/* RedundancySupport - ns=0;i=3709 */

static UA_StatusCode function_namespace0_generated_89_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 851);
attr.displayName = UA_LOCALIZEDTEXT("", "RedundancySupport");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 3709),
UA_NODEID_NUMERIC(ns[0], 2296),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "RedundancySupport"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_89_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3709)
);
}

/* GetMonitoredItems - ns=0;i=11492 */

static UA_StatusCode function_namespace0_generated_90_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GetMonitoredItems");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[0], 11492),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "GetMonitoredItems"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace0_generated_90_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11492)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=0;i=11493 */

static UA_StatusCode function_namespace0_generated_91_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_0_i_11493_variant_DataContents[1];

UA_init(&variablenode_ns_0_i_11493_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_0_i_11493_variant_DataContents[0].name = UA_STRING("SubscriptionId");
variablenode_ns_0_i_11493_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_0_i_11493_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_11493_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11493),
UA_NODEID_NUMERIC(ns[0], 11492),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace0_generated_91_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11493)
);
}

/* OutputArguments - ns=0;i=11494 */

static UA_StatusCode function_namespace0_generated_92_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_0_i_11494_variant_DataContents[2];

UA_init(&variablenode_ns_0_i_11494_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_0_i_11494_variant_DataContents[0].name = UA_STRING("ServerHandles");
variablenode_ns_0_i_11494_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_0_i_11494_variant_DataContents[0].valueRank = (UA_Int32) 1;
UA_STACKARRAY(UA_UInt32, variablenode_ns_0_i_11494_variant_DataContents0_arrayDimensions, 1);
UA_init(variablenode_ns_0_i_11494_variant_DataContents0_arrayDimensions, &UA_TYPES[UA_TYPES_UINT32]);
variablenode_ns_0_i_11494_variant_DataContents0_arrayDimensions[0] = (UA_UInt32) 0;
variablenode_ns_0_i_11494_variant_DataContents[0].arrayDimensionsSize = 1;
variablenode_ns_0_i_11494_variant_DataContents[0].arrayDimensions = variablenode_ns_0_i_11494_variant_DataContents0_arrayDimensions;

UA_init(&variablenode_ns_0_i_11494_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_0_i_11494_variant_DataContents[1].name = UA_STRING("ClientHandles");
variablenode_ns_0_i_11494_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_0_i_11494_variant_DataContents[1].valueRank = (UA_Int32) 1;
UA_STACKARRAY(UA_UInt32, variablenode_ns_0_i_11494_variant_DataContents1_arrayDimensions, 1);
UA_init(variablenode_ns_0_i_11494_variant_DataContents1_arrayDimensions, &UA_TYPES[UA_TYPES_UINT32]);
variablenode_ns_0_i_11494_variant_DataContents1_arrayDimensions[0] = (UA_UInt32) 0;
variablenode_ns_0_i_11494_variant_DataContents[1].arrayDimensionsSize = 1;
variablenode_ns_0_i_11494_variant_DataContents[1].arrayDimensions = variablenode_ns_0_i_11494_variant_DataContents1_arrayDimensions;
UA_Variant_setArray(&attr.value, &variablenode_ns_0_i_11494_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11494),
UA_NODEID_NUMERIC(ns[0], 11492),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


return retVal;
}

static UA_StatusCode function_namespace0_generated_92_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11494)
);
}

/* ServerStatus - ns=0;i=2256 */

static UA_StatusCode function_namespace0_generated_93_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 862);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerStatus");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerStatus"),
UA_NODEID_NUMERIC(ns[0], 2138),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_93_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2256)
);
}

/* SecondsTillShutdown - ns=0;i=2992 */

static UA_StatusCode function_namespace0_generated_94_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SecondsTillShutdown");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2992),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SecondsTillShutdown"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_94_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2992)
);
}

/* State - ns=0;i=2259 */

static UA_StatusCode function_namespace0_generated_95_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 852);
attr.displayName = UA_LOCALIZEDTEXT("", "State");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2259),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "State"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_95_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2259)
);
}

/* CurrentTime - ns=0;i=2258 */

static UA_StatusCode function_namespace0_generated_96_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 294);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentTime");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2258),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CurrentTime"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_96_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2258)
);
}

/* BuildInfo - ns=0;i=2260 */

static UA_StatusCode function_namespace0_generated_97_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 338);
attr.displayName = UA_LOCALIZEDTEXT("", "BuildInfo");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "BuildInfo"),
UA_NODEID_NUMERIC(ns[0], 3051),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_97_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2260)
);
}

/* SoftwareVersion - ns=0;i=2264 */

static UA_StatusCode function_namespace0_generated_98_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "SoftwareVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2264),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SoftwareVersion"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_98_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2264)
);
}

/* ProductUri - ns=0;i=2262 */

static UA_StatusCode function_namespace0_generated_99_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductUri");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2262),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ProductUri"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_99_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2262)
);
}

/* BuildNumber - ns=0;i=2265 */

static UA_StatusCode function_namespace0_generated_100_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "BuildNumber");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2265),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "BuildNumber"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_100_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2265)
);
}

/* ProductName - ns=0;i=2261 */

static UA_StatusCode function_namespace0_generated_101_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductName");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2261),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ProductName"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_101_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2261)
);
}

/* BuildDate - ns=0;i=2266 */

static UA_StatusCode function_namespace0_generated_102_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 294);
attr.displayName = UA_LOCALIZEDTEXT("", "BuildDate");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2266),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "BuildDate"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_102_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2266)
);
}

/* ManufacturerName - ns=0;i=2263 */

static UA_StatusCode function_namespace0_generated_103_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "ManufacturerName");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2263),
UA_NODEID_NUMERIC(ns[0], 2260),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ManufacturerName"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_103_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2263)
);
}

/* ShutdownReason - ns=0;i=2993 */

static UA_StatusCode function_namespace0_generated_104_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 21);
attr.displayName = UA_LOCALIZEDTEXT("", "ShutdownReason");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2993),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ShutdownReason"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_104_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2993)
);
}

/* StartTime - ns=0;i=2257 */

static UA_StatusCode function_namespace0_generated_105_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 294);
attr.displayName = UA_LOCALIZEDTEXT("", "StartTime");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2257),
UA_NODEID_NUMERIC(ns[0], 2256),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "StartTime"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_105_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2257)
);
}

/* ServerDiagnostics - ns=0;i=2274 */

static UA_StatusCode function_namespace0_generated_106_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerDiagnostics");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2274),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerDiagnostics"),
UA_NODEID_NUMERIC(ns[0], 2020),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_106_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2274)
);
}

/* ServerDiagnosticsSummary - ns=0;i=2275 */

static UA_StatusCode function_namespace0_generated_107_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 859);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerDiagnosticsSummary");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 2274),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerDiagnosticsSummary"),
UA_NODEID_NUMERIC(ns[0], 2150),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_107_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2275)
);
}

/* RejectedRequestsCount - ns=0;i=2288 */

static UA_StatusCode function_namespace0_generated_108_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "RejectedRequestsCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2288),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "RejectedRequestsCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_108_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2288)
);
}

/* SecurityRejectedRequestsCount - ns=0;i=2287 */

static UA_StatusCode function_namespace0_generated_109_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SecurityRejectedRequestsCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2287),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SecurityRejectedRequestsCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_109_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2287)
);
}

/* CumulatedSessionCount - ns=0;i=2278 */

static UA_StatusCode function_namespace0_generated_110_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CumulatedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2278),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CumulatedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_110_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2278)
);
}

/* CurrentSubscriptionCount - ns=0;i=2285 */

static UA_StatusCode function_namespace0_generated_111_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentSubscriptionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2285),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CurrentSubscriptionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_111_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2285)
);
}

/* RejectedSessionCount - ns=0;i=3705 */

static UA_StatusCode function_namespace0_generated_112_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "RejectedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 3705),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "RejectedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_112_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3705)
);
}

/* SessionAbortCount - ns=0;i=2282 */

static UA_StatusCode function_namespace0_generated_113_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SessionAbortCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2282),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SessionAbortCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_113_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2282)
);
}

/* CurrentSessionCount - ns=0;i=2277 */

static UA_StatusCode function_namespace0_generated_114_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2277),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CurrentSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_114_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2277)
);
}

/* ServerViewCount - ns=0;i=2276 */

static UA_StatusCode function_namespace0_generated_115_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerViewCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2276),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerViewCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_115_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2276)
);
}

/* CumulatedSubscriptionCount - ns=0;i=2286 */

static UA_StatusCode function_namespace0_generated_116_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "CumulatedSubscriptionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2286),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CumulatedSubscriptionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_116_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2286)
);
}

/* SecurityRejectedSessionCount - ns=0;i=2279 */

static UA_StatusCode function_namespace0_generated_117_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SecurityRejectedSessionCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2279),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SecurityRejectedSessionCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_117_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2279)
);
}

/* SessionTimeoutCount - ns=0;i=2281 */

static UA_StatusCode function_namespace0_generated_118_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "SessionTimeoutCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2281),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "SessionTimeoutCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_118_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2281)
);
}

/* PublishingIntervalCount - ns=0;i=2284 */

static UA_StatusCode function_namespace0_generated_119_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "PublishingIntervalCount");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2284),
UA_NODEID_NUMERIC(ns[0], 2275),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "PublishingIntervalCount"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_119_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2284)
);
}

/* EnabledFlag - ns=0;i=2294 */

static UA_StatusCode function_namespace0_generated_120_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
attr.displayName = UA_LOCALIZEDTEXT("", "EnabledFlag");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2294),
UA_NODEID_NUMERIC(ns[0], 2274),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EnabledFlag"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_120_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2294)
);
}

/* ServerCapabilities - ns=0;i=2268 */

static UA_StatusCode function_namespace0_generated_121_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ServerCapabilities");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ServerCapabilities"),
UA_NODEID_NUMERIC(ns[0], 2013),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_121_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2268)
);
}

/* LocaleIdArray - ns=0;i=2271 */

static UA_StatusCode function_namespace0_generated_122_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 295);
attr.displayName = UA_LOCALIZEDTEXT("", "LocaleIdArray");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2271),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "LocaleIdArray"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_122_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2271)
);
}

/* MaxBrowseContinuationPoints - ns=0;i=2735 */

static UA_StatusCode function_namespace0_generated_123_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxBrowseContinuationPoints");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2735),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxBrowseContinuationPoints"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_123_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2735)
);
}

/* AggregateFunctions - ns=0;i=2997 */

static UA_StatusCode function_namespace0_generated_124_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "AggregateFunctions");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2997),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "AggregateFunctions"),
UA_NODEID_NUMERIC(ns[0], 61),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_124_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2997)
);
}

/* MaxQueryContinuationPoints - ns=0;i=2736 */

static UA_StatusCode function_namespace0_generated_125_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxQueryContinuationPoints");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2736),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxQueryContinuationPoints"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_125_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2736)
);
}

/* MaxHistoryContinuationPoints - ns=0;i=2737 */

static UA_StatusCode function_namespace0_generated_126_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxHistoryContinuationPoints");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2737),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxHistoryContinuationPoints"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_126_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2737)
);
}

/* SoftwareCertificates - ns=0;i=3704 */

static UA_StatusCode function_namespace0_generated_127_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 344);
attr.displayName = UA_LOCALIZEDTEXT("", "SoftwareCertificates");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 3704),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "SoftwareCertificates"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_127_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3704)
);
}

/* ServerProfileArray - ns=0;i=2269 */

static UA_StatusCode function_namespace0_generated_128_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "ServerProfileArray");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2269),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "ServerProfileArray"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_128_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2269)
);
}

/* OperationLimits - ns=0;i=11704 */

static UA_StatusCode function_namespace0_generated_129_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "OperationLimits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "OperationLimits"),
UA_NODEID_NUMERIC(ns[0], 11564),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_129_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11704)
);
}

/* MaxNodesPerMethodCall - ns=0;i=11709 */

static UA_StatusCode function_namespace0_generated_130_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerMethodCall");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11709),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerMethodCall"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_130_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11709)
);
}

/* MaxNodesPerRead - ns=0;i=11705 */

static UA_StatusCode function_namespace0_generated_131_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerRead");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11705),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerRead"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_131_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11705)
);
}

/* MaxNodesPerNodeManagement - ns=0;i=11713 */

static UA_StatusCode function_namespace0_generated_132_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerNodeManagement");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11713),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerNodeManagement"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_132_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11713)
);
}

/* MaxMonitoredItemsPerCall - ns=0;i=11714 */

static UA_StatusCode function_namespace0_generated_133_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxMonitoredItemsPerCall");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11714),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxMonitoredItemsPerCall"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_133_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11714)
);
}

/* MaxNodesPerWrite - ns=0;i=11707 */

static UA_StatusCode function_namespace0_generated_134_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerWrite");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11707),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerWrite"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_134_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11707)
);
}

/* MaxNodesPerRegisterNodes - ns=0;i=11711 */

static UA_StatusCode function_namespace0_generated_135_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerRegisterNodes");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11711),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerRegisterNodes"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_135_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11711)
);
}

/* MaxNodesPerBrowse - ns=0;i=11710 */

static UA_StatusCode function_namespace0_generated_136_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerBrowse");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11710),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerBrowse"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_136_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11710)
);
}

/* MaxNodesPerTranslateBrowsePathsToNodeIds - ns=0;i=11712 */

static UA_StatusCode function_namespace0_generated_137_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxNodesPerTranslateBrowsePathsToNodeIds");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 11712),
UA_NODEID_NUMERIC(ns[0], 11704),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MaxNodesPerTranslateBrowsePathsToNodeIds"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_137_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 11712)
);
}

/* ModellingRules - ns=0;i=2996 */

static UA_StatusCode function_namespace0_generated_138_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ModellingRules");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2996),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "ModellingRules"),
UA_NODEID_NUMERIC(ns[0], 61),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_138_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2996)
);
}

/* MinSupportedSampleRate - ns=0;i=2272 */

static UA_StatusCode function_namespace0_generated_139_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290);
attr.displayName = UA_LOCALIZEDTEXT("", "MinSupportedSampleRate");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2272),
UA_NODEID_NUMERIC(ns[0], 2268),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "MinSupportedSampleRate"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_139_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2272)
);
}

/* VendorServerInfo - ns=0;i=2295 */

static UA_StatusCode function_namespace0_generated_140_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "VendorServerInfo");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2295),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "VendorServerInfo"),
UA_NODEID_NUMERIC(ns[0], 2033),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_140_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2295)
);
}

/* NamespaceArray - ns=0;i=2255 */

static UA_StatusCode function_namespace0_generated_141_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 1000.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceArray");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 2255),
UA_NODEID_NUMERIC(ns[0], 2253),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceArray"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_141_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2255)
);
}

/* VendorServerInfo - ns=0;i=2011 */

static UA_StatusCode function_namespace0_generated_142_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "VendorServerInfo");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 2011),
UA_NODEID_NUMERIC(ns[0], 2004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "VendorServerInfo"),
UA_NODEID_NUMERIC(ns[0], 2033),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_142_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 2011)
);
}

/* ModellingRuleType - ns=0;i=77 */

static UA_StatusCode function_namespace0_generated_143_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ModellingRuleType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 77),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "ModellingRuleType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_143_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 77)
);
}

/* Mandatory - ns=0;i=78 */

static UA_StatusCode function_namespace0_generated_144_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Mandatory");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 78),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Mandatory"),
UA_NODEID_NUMERIC(ns[0], 77),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2159), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 12169), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2161), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2162), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2163), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2035), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2153), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2157), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2154), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2152), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2156), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2160), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 7611), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2011), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2155), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 78), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 2151), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_144_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 78)
);
}

/* NamingRule - ns=0;i=112 */

static UA_StatusCode function_namespace0_generated_145_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 120);
UA_Int32 *variablenode_ns_0_i_112_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_0_i_112_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_0_i_112_variant_DataContents);
*variablenode_ns_0_i_112_variant_DataContents = (UA_Int32) 1;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_112_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamingRule");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 112),
UA_NODEID_NUMERIC(ns[0], 78),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamingRule"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_0_i_112_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace0_generated_145_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 112)
);
}

/* NamingRule - ns=0;i=111 */

static UA_StatusCode function_namespace0_generated_146_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 120);
UA_Int32 *variablenode_ns_0_i_111_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_0_i_111_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_0_i_111_variant_DataContents);
*variablenode_ns_0_i_111_variant_DataContents = (UA_Int32) 1;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_111_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamingRule");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 111),
UA_NODEID_NUMERIC(ns[0], 77),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamingRule"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_0_i_111_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 111), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace0_generated_146_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 111)
);
}

/* Optional - ns=0;i=80 */

static UA_StatusCode function_namespace0_generated_147_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Optional");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 80),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Optional"),
UA_NODEID_NUMERIC(ns[0], 77),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11567), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11551), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11565), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11571), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11573), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11574), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11572), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11569), false);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 80), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11570), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_147_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 80)
);
}

/* NamingRule - ns=0;i=113 */

static UA_StatusCode function_namespace0_generated_148_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 120);
UA_Int32 *variablenode_ns_0_i_113_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_0_i_113_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_0_i_113_variant_DataContents);
*variablenode_ns_0_i_113_variant_DataContents = (UA_Int32) 2;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_113_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamingRule");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 113),
UA_NODEID_NUMERIC(ns[0], 80),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamingRule"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_0_i_113_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace0_generated_148_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 113)
);
}

/* DataTypeEncodingType - ns=0;i=76 */

static UA_StatusCode function_namespace0_generated_149_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeEncodingType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 76),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DataTypeEncodingType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_149_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 76)
);
}

/* Default Binary - ns=0;i=8251 */

static UA_StatusCode function_namespace0_generated_150_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Default Binary");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 8251),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Default Binary"),
UA_NODEID_NUMERIC(ns[0], 76),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 8251), UA_NODEID_NUMERIC(ns[0], 38), UA_EXPANDEDNODEID_NUMERIC(ns[0], 7594), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_150_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 8251)
);
}

/* Default Binary - ns=0;i=298 */

static UA_StatusCode function_namespace0_generated_151_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Default Binary");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 298),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Default Binary"),
UA_NODEID_NUMERIC(ns[0], 76),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 298), UA_NODEID_NUMERIC(ns[0], 38), UA_EXPANDEDNODEID_NUMERIC(ns[0], 296), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_151_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 298)
);
}

/* DataTypeSystemType - ns=0;i=75 */

static UA_StatusCode function_namespace0_generated_152_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeSystemType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[0], 75),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DataTypeSystemType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_152_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 75)
);
}

/* XML Schema - ns=0;i=92 */

static UA_StatusCode function_namespace0_generated_153_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "XML Schema");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 92),
UA_NODEID_NUMERIC(ns[0], 90),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "XML Schema"),
UA_NODEID_NUMERIC(ns[0], 75),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_153_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 92)
);
}

/* OPC Binary - ns=0;i=93 */

static UA_StatusCode function_namespace0_generated_154_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "OPC Binary");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 93),
UA_NODEID_NUMERIC(ns[0], 90),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[0], "OPC Binary"),
UA_NODEID_NUMERIC(ns[0], 75),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_154_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 93)
);
}

/* DataTypeDictionaryType - ns=0;i=72 */

static UA_StatusCode function_namespace0_generated_155_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableTypeAttributes attr = UA_VariableTypeAttributes_default;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 15);
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeDictionaryType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLETYPE,
UA_NODEID_NUMERIC(ns[0], 72),
UA_NODEID_NUMERIC(ns[0], 63),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DataTypeDictionaryType"),
UA_NODEID_NUMERIC(ns[0], 0),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_155_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 72)
);
}

/* Opc.Ua - ns=0;i=7617 */

static UA_StatusCode function_namespace0_generated_156_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 15);
UA_ByteString *variablenode_ns_0_i_7617_variant_DataContents =  UA_ByteString_new();
if (!variablenode_ns_0_i_7617_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_ByteString_init(variablenode_ns_0_i_7617_variant_DataContents);
*variablenode_ns_0_i_7617_variant_DataContents = UA_BYTESTRING_NULL;
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_7617_variant_DataContents, &UA_TYPES[UA_TYPES_BYTESTRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Opc.Ua");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 7617),
UA_NODEID_NUMERIC(ns[0], 93),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "Opc.Ua"),
UA_NODEID_NUMERIC(ns[0], 72),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
variablenode_ns_0_i_7617_variant_DataContents->data = NULL;
variablenode_ns_0_i_7617_variant_DataContents->length = 0;
UA_ByteString_delete(variablenode_ns_0_i_7617_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace0_generated_156_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7617)
);
}

/* NamespaceUri - ns=0;i=107 */

static UA_StatusCode function_namespace0_generated_157_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A URI that uniquely identifies the dictionary.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 107),
UA_NODEID_NUMERIC(ns[0], 72),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceUri"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 107), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace0_generated_157_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 107)
);
}

/* DataTypeVersion - ns=0;i=106 */

static UA_StatusCode function_namespace0_generated_158_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 106),
UA_NODEID_NUMERIC(ns[0], 72),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "DataTypeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 106), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace0_generated_158_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 106)
);
}

/* DataTypeDescriptionType - ns=0;i=69 */

static UA_StatusCode function_namespace0_generated_159_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableTypeAttributes attr = UA_VariableTypeAttributes_default;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeDescriptionType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLETYPE,
UA_NODEID_NUMERIC(ns[0], 69),
UA_NODEID_NUMERIC(ns[0], 63),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[0], "DataTypeDescriptionType"),
UA_NODEID_NUMERIC(ns[0], 0),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLETYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_159_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 69)
);
}

/* Argument - ns=0;i=7650 */

static UA_StatusCode function_namespace0_generated_160_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_0_i_7650_variant_DataContents =  UA_String_new();
if (!variablenode_ns_0_i_7650_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_0_i_7650_variant_DataContents);
*variablenode_ns_0_i_7650_variant_DataContents = UA_STRING_ALLOC("Argument");
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_7650_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Argument");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 7650),
UA_NODEID_NUMERIC(ns[0], 7617),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "Argument"),
UA_NODEID_NUMERIC(ns[0], 69),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_0_i_7650_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 7650), UA_NODEID_NUMERIC(ns[0], 39), UA_EXPANDEDNODEID_NUMERIC(ns[0], 298), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_160_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7650)
);
}

/* EnumValueType - ns=0;i=7656 */

static UA_StatusCode function_namespace0_generated_161_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_0_i_7656_variant_DataContents =  UA_String_new();
if (!variablenode_ns_0_i_7656_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_0_i_7656_variant_DataContents);
*variablenode_ns_0_i_7656_variant_DataContents = UA_STRING_ALLOC("EnumValueType");
UA_Variant_setScalar(&attr.value, variablenode_ns_0_i_7656_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumValueType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 7656),
UA_NODEID_NUMERIC(ns[0], 7617),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "EnumValueType"),
UA_NODEID_NUMERIC(ns[0], 69),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_0_i_7656_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 7656), UA_NODEID_NUMERIC(ns[0], 39), UA_EXPANDEDNODEID_NUMERIC(ns[0], 8251), false);
return retVal;
}

static UA_StatusCode function_namespace0_generated_161_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 7656)
);
}

/* DictionaryFragment - ns=0;i=105 */

static UA_StatusCode function_namespace0_generated_162_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 15);
attr.displayName = UA_LOCALIZEDTEXT("", "DictionaryFragment");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 105),
UA_NODEID_NUMERIC(ns[0], 69),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "DictionaryFragment"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 105), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace0_generated_162_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 105)
);
}

/* DataTypeVersion - ns=0;i=104 */

static UA_StatusCode function_namespace0_generated_163_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DataTypeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[0], 104),
UA_NODEID_NUMERIC(ns[0], 69),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "DataTypeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[0], 104), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace0_generated_163_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 104)
);
}

/* Default XML - ns=0;i=3063 */

static UA_StatusCode function_namespace0_generated_164_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Default XML");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 3063),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Default XML"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_164_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3063)
);
}

/* Default Binary - ns=0;i=3062 */

static UA_StatusCode function_namespace0_generated_165_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Default Binary");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[0], 3062),
UA_NODEID_NUMERIC(ns[0], 0),
UA_NODEID_NUMERIC(ns[0], 0),
UA_QUALIFIEDNAME(ns[0], "Default Binary"),
UA_NODEID_NUMERIC(ns[0], 58),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace0_generated_165_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[0], 3062)
);
}

UA_StatusCode namespace0_generated(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[1];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
bool dummy = (
!(retVal = function_namespace0_generated_0_begin(server, ns)) &&
!(retVal = function_namespace0_generated_1_begin(server, ns)) &&
!(retVal = function_namespace0_generated_2_begin(server, ns)) &&
!(retVal = function_namespace0_generated_3_begin(server, ns)) &&
!(retVal = function_namespace0_generated_4_begin(server, ns)) &&
!(retVal = function_namespace0_generated_5_begin(server, ns)) &&
!(retVal = function_namespace0_generated_6_begin(server, ns)) &&
!(retVal = function_namespace0_generated_7_begin(server, ns)) &&
!(retVal = function_namespace0_generated_8_begin(server, ns)) &&
!(retVal = function_namespace0_generated_9_begin(server, ns)) &&
!(retVal = function_namespace0_generated_10_begin(server, ns)) &&
!(retVal = function_namespace0_generated_11_begin(server, ns)) &&
!(retVal = function_namespace0_generated_12_begin(server, ns)) &&
!(retVal = function_namespace0_generated_13_begin(server, ns)) &&
!(retVal = function_namespace0_generated_14_begin(server, ns)) &&
!(retVal = function_namespace0_generated_15_begin(server, ns)) &&
!(retVal = function_namespace0_generated_16_begin(server, ns)) &&
!(retVal = function_namespace0_generated_17_begin(server, ns)) &&
!(retVal = function_namespace0_generated_18_begin(server, ns)) &&
!(retVal = function_namespace0_generated_19_begin(server, ns)) &&
!(retVal = function_namespace0_generated_20_begin(server, ns)) &&
!(retVal = function_namespace0_generated_21_begin(server, ns)) &&
!(retVal = function_namespace0_generated_22_begin(server, ns)) &&
!(retVal = function_namespace0_generated_23_begin(server, ns)) &&
!(retVal = function_namespace0_generated_24_begin(server, ns)) &&
!(retVal = function_namespace0_generated_25_begin(server, ns)) &&
!(retVal = function_namespace0_generated_26_begin(server, ns)) &&
!(retVal = function_namespace0_generated_27_begin(server, ns)) &&
!(retVal = function_namespace0_generated_28_begin(server, ns)) &&
!(retVal = function_namespace0_generated_29_begin(server, ns)) &&
!(retVal = function_namespace0_generated_30_begin(server, ns)) &&
!(retVal = function_namespace0_generated_31_begin(server, ns)) &&
!(retVal = function_namespace0_generated_32_begin(server, ns)) &&
!(retVal = function_namespace0_generated_33_begin(server, ns)) &&
!(retVal = function_namespace0_generated_34_begin(server, ns)) &&
!(retVal = function_namespace0_generated_35_begin(server, ns)) &&
!(retVal = function_namespace0_generated_36_begin(server, ns)) &&
!(retVal = function_namespace0_generated_37_begin(server, ns)) &&
!(retVal = function_namespace0_generated_38_begin(server, ns)) &&
!(retVal = function_namespace0_generated_39_begin(server, ns)) &&
!(retVal = function_namespace0_generated_40_begin(server, ns)) &&
!(retVal = function_namespace0_generated_41_begin(server, ns)) &&
!(retVal = function_namespace0_generated_42_begin(server, ns)) &&
!(retVal = function_namespace0_generated_43_begin(server, ns)) &&
!(retVal = function_namespace0_generated_44_begin(server, ns)) &&
!(retVal = function_namespace0_generated_45_begin(server, ns)) &&
!(retVal = function_namespace0_generated_46_begin(server, ns)) &&
!(retVal = function_namespace0_generated_47_begin(server, ns)) &&
!(retVal = function_namespace0_generated_48_begin(server, ns)) &&
!(retVal = function_namespace0_generated_49_begin(server, ns)) &&
!(retVal = function_namespace0_generated_50_begin(server, ns)) &&
!(retVal = function_namespace0_generated_51_begin(server, ns)) &&
!(retVal = function_namespace0_generated_52_begin(server, ns)) &&
!(retVal = function_namespace0_generated_53_begin(server, ns)) &&
!(retVal = function_namespace0_generated_54_begin(server, ns)) &&
!(retVal = function_namespace0_generated_55_begin(server, ns)) &&
!(retVal = function_namespace0_generated_56_begin(server, ns)) &&
!(retVal = function_namespace0_generated_57_begin(server, ns)) &&
!(retVal = function_namespace0_generated_58_begin(server, ns)) &&
!(retVal = function_namespace0_generated_59_begin(server, ns)) &&
!(retVal = function_namespace0_generated_60_begin(server, ns)) &&
!(retVal = function_namespace0_generated_61_begin(server, ns)) &&
!(retVal = function_namespace0_generated_62_begin(server, ns)) &&
!(retVal = function_namespace0_generated_63_begin(server, ns)) &&
!(retVal = function_namespace0_generated_64_begin(server, ns)) &&
!(retVal = function_namespace0_generated_65_begin(server, ns)) &&
!(retVal = function_namespace0_generated_66_begin(server, ns)) &&
!(retVal = function_namespace0_generated_67_begin(server, ns)) &&
!(retVal = function_namespace0_generated_68_begin(server, ns)) &&
!(retVal = function_namespace0_generated_69_begin(server, ns)) &&
!(retVal = function_namespace0_generated_70_begin(server, ns)) &&
!(retVal = function_namespace0_generated_71_begin(server, ns)) &&
!(retVal = function_namespace0_generated_72_begin(server, ns)) &&
!(retVal = function_namespace0_generated_73_begin(server, ns)) &&
!(retVal = function_namespace0_generated_74_begin(server, ns)) &&
!(retVal = function_namespace0_generated_75_begin(server, ns)) &&
!(retVal = function_namespace0_generated_76_begin(server, ns)) &&
!(retVal = function_namespace0_generated_77_begin(server, ns)) &&
!(retVal = function_namespace0_generated_78_begin(server, ns)) &&
!(retVal = function_namespace0_generated_79_begin(server, ns)) &&
!(retVal = function_namespace0_generated_80_begin(server, ns)) &&
!(retVal = function_namespace0_generated_81_begin(server, ns)) &&
!(retVal = function_namespace0_generated_82_begin(server, ns)) &&
!(retVal = function_namespace0_generated_83_begin(server, ns)) &&
!(retVal = function_namespace0_generated_84_begin(server, ns)) &&
!(retVal = function_namespace0_generated_85_begin(server, ns)) &&
!(retVal = function_namespace0_generated_86_begin(server, ns)) &&
!(retVal = function_namespace0_generated_87_begin(server, ns)) &&
!(retVal = function_namespace0_generated_88_begin(server, ns)) &&
!(retVal = function_namespace0_generated_89_begin(server, ns)) &&
!(retVal = function_namespace0_generated_90_begin(server, ns)) &&
!(retVal = function_namespace0_generated_91_begin(server, ns)) &&
!(retVal = function_namespace0_generated_92_begin(server, ns)) &&
!(retVal = function_namespace0_generated_93_begin(server, ns)) &&
!(retVal = function_namespace0_generated_94_begin(server, ns)) &&
!(retVal = function_namespace0_generated_95_begin(server, ns)) &&
!(retVal = function_namespace0_generated_96_begin(server, ns)) &&
!(retVal = function_namespace0_generated_97_begin(server, ns)) &&
!(retVal = function_namespace0_generated_98_begin(server, ns)) &&
!(retVal = function_namespace0_generated_99_begin(server, ns)) &&
!(retVal = function_namespace0_generated_100_begin(server, ns)) &&
!(retVal = function_namespace0_generated_101_begin(server, ns)) &&
!(retVal = function_namespace0_generated_102_begin(server, ns)) &&
!(retVal = function_namespace0_generated_103_begin(server, ns)) &&
!(retVal = function_namespace0_generated_104_begin(server, ns)) &&
!(retVal = function_namespace0_generated_105_begin(server, ns)) &&
!(retVal = function_namespace0_generated_106_begin(server, ns)) &&
!(retVal = function_namespace0_generated_107_begin(server, ns)) &&
!(retVal = function_namespace0_generated_108_begin(server, ns)) &&
!(retVal = function_namespace0_generated_109_begin(server, ns)) &&
!(retVal = function_namespace0_generated_110_begin(server, ns)) &&
!(retVal = function_namespace0_generated_111_begin(server, ns)) &&
!(retVal = function_namespace0_generated_112_begin(server, ns)) &&
!(retVal = function_namespace0_generated_113_begin(server, ns)) &&
!(retVal = function_namespace0_generated_114_begin(server, ns)) &&
!(retVal = function_namespace0_generated_115_begin(server, ns)) &&
!(retVal = function_namespace0_generated_116_begin(server, ns)) &&
!(retVal = function_namespace0_generated_117_begin(server, ns)) &&
!(retVal = function_namespace0_generated_118_begin(server, ns)) &&
!(retVal = function_namespace0_generated_119_begin(server, ns)) &&
!(retVal = function_namespace0_generated_120_begin(server, ns)) &&
!(retVal = function_namespace0_generated_121_begin(server, ns)) &&
!(retVal = function_namespace0_generated_122_begin(server, ns)) &&
!(retVal = function_namespace0_generated_123_begin(server, ns)) &&
!(retVal = function_namespace0_generated_124_begin(server, ns)) &&
!(retVal = function_namespace0_generated_125_begin(server, ns)) &&
!(retVal = function_namespace0_generated_126_begin(server, ns)) &&
!(retVal = function_namespace0_generated_127_begin(server, ns)) &&
!(retVal = function_namespace0_generated_128_begin(server, ns)) &&
!(retVal = function_namespace0_generated_129_begin(server, ns)) &&
!(retVal = function_namespace0_generated_130_begin(server, ns)) &&
!(retVal = function_namespace0_generated_131_begin(server, ns)) &&
!(retVal = function_namespace0_generated_132_begin(server, ns)) &&
!(retVal = function_namespace0_generated_133_begin(server, ns)) &&
!(retVal = function_namespace0_generated_134_begin(server, ns)) &&
!(retVal = function_namespace0_generated_135_begin(server, ns)) &&
!(retVal = function_namespace0_generated_136_begin(server, ns)) &&
!(retVal = function_namespace0_generated_137_begin(server, ns)) &&
!(retVal = function_namespace0_generated_138_begin(server, ns)) &&
!(retVal = function_namespace0_generated_139_begin(server, ns)) &&
!(retVal = function_namespace0_generated_140_begin(server, ns)) &&
!(retVal = function_namespace0_generated_141_begin(server, ns)) &&
!(retVal = function_namespace0_generated_142_begin(server, ns)) &&
!(retVal = function_namespace0_generated_143_begin(server, ns)) &&
!(retVal = function_namespace0_generated_144_begin(server, ns)) &&
!(retVal = function_namespace0_generated_145_begin(server, ns)) &&
!(retVal = function_namespace0_generated_146_begin(server, ns)) &&
!(retVal = function_namespace0_generated_147_begin(server, ns)) &&
!(retVal = function_namespace0_generated_148_begin(server, ns)) &&
!(retVal = function_namespace0_generated_149_begin(server, ns)) &&
!(retVal = function_namespace0_generated_150_begin(server, ns)) &&
!(retVal = function_namespace0_generated_151_begin(server, ns)) &&
!(retVal = function_namespace0_generated_152_begin(server, ns)) &&
!(retVal = function_namespace0_generated_153_begin(server, ns)) &&
!(retVal = function_namespace0_generated_154_begin(server, ns)) &&
!(retVal = function_namespace0_generated_155_begin(server, ns)) &&
!(retVal = function_namespace0_generated_156_begin(server, ns)) &&
!(retVal = function_namespace0_generated_157_begin(server, ns)) &&
!(retVal = function_namespace0_generated_158_begin(server, ns)) &&
!(retVal = function_namespace0_generated_159_begin(server, ns)) &&
!(retVal = function_namespace0_generated_160_begin(server, ns)) &&
!(retVal = function_namespace0_generated_161_begin(server, ns)) &&
!(retVal = function_namespace0_generated_162_begin(server, ns)) &&
!(retVal = function_namespace0_generated_163_begin(server, ns)) &&
!(retVal = function_namespace0_generated_164_begin(server, ns)) &&
!(retVal = function_namespace0_generated_165_begin(server, ns)) &&
!(retVal = function_namespace0_generated_165_finish(server, ns)) &&
!(retVal = function_namespace0_generated_164_finish(server, ns)) &&
!(retVal = function_namespace0_generated_163_finish(server, ns)) &&
!(retVal = function_namespace0_generated_162_finish(server, ns)) &&
!(retVal = function_namespace0_generated_161_finish(server, ns)) &&
!(retVal = function_namespace0_generated_160_finish(server, ns)) &&
!(retVal = function_namespace0_generated_159_finish(server, ns)) &&
!(retVal = function_namespace0_generated_158_finish(server, ns)) &&
!(retVal = function_namespace0_generated_157_finish(server, ns)) &&
!(retVal = function_namespace0_generated_156_finish(server, ns)) &&
!(retVal = function_namespace0_generated_155_finish(server, ns)) &&
!(retVal = function_namespace0_generated_154_finish(server, ns)) &&
!(retVal = function_namespace0_generated_153_finish(server, ns)) &&
!(retVal = function_namespace0_generated_152_finish(server, ns)) &&
!(retVal = function_namespace0_generated_151_finish(server, ns)) &&
!(retVal = function_namespace0_generated_150_finish(server, ns)) &&
!(retVal = function_namespace0_generated_149_finish(server, ns)) &&
!(retVal = function_namespace0_generated_148_finish(server, ns)) &&
!(retVal = function_namespace0_generated_147_finish(server, ns)) &&
!(retVal = function_namespace0_generated_146_finish(server, ns)) &&
!(retVal = function_namespace0_generated_145_finish(server, ns)) &&
!(retVal = function_namespace0_generated_144_finish(server, ns)) &&
!(retVal = function_namespace0_generated_143_finish(server, ns)) &&
!(retVal = function_namespace0_generated_142_finish(server, ns)) &&
!(retVal = function_namespace0_generated_141_finish(server, ns)) &&
!(retVal = function_namespace0_generated_140_finish(server, ns)) &&
!(retVal = function_namespace0_generated_139_finish(server, ns)) &&
!(retVal = function_namespace0_generated_138_finish(server, ns)) &&
!(retVal = function_namespace0_generated_137_finish(server, ns)) &&
!(retVal = function_namespace0_generated_136_finish(server, ns)) &&
!(retVal = function_namespace0_generated_135_finish(server, ns)) &&
!(retVal = function_namespace0_generated_134_finish(server, ns)) &&
!(retVal = function_namespace0_generated_133_finish(server, ns)) &&
!(retVal = function_namespace0_generated_132_finish(server, ns)) &&
!(retVal = function_namespace0_generated_131_finish(server, ns)) &&
!(retVal = function_namespace0_generated_130_finish(server, ns)) &&
!(retVal = function_namespace0_generated_129_finish(server, ns)) &&
!(retVal = function_namespace0_generated_128_finish(server, ns)) &&
!(retVal = function_namespace0_generated_127_finish(server, ns)) &&
!(retVal = function_namespace0_generated_126_finish(server, ns)) &&
!(retVal = function_namespace0_generated_125_finish(server, ns)) &&
!(retVal = function_namespace0_generated_124_finish(server, ns)) &&
!(retVal = function_namespace0_generated_123_finish(server, ns)) &&
!(retVal = function_namespace0_generated_122_finish(server, ns)) &&
!(retVal = function_namespace0_generated_121_finish(server, ns)) &&
!(retVal = function_namespace0_generated_120_finish(server, ns)) &&
!(retVal = function_namespace0_generated_119_finish(server, ns)) &&
!(retVal = function_namespace0_generated_118_finish(server, ns)) &&
!(retVal = function_namespace0_generated_117_finish(server, ns)) &&
!(retVal = function_namespace0_generated_116_finish(server, ns)) &&
!(retVal = function_namespace0_generated_115_finish(server, ns)) &&
!(retVal = function_namespace0_generated_114_finish(server, ns)) &&
!(retVal = function_namespace0_generated_113_finish(server, ns)) &&
!(retVal = function_namespace0_generated_112_finish(server, ns)) &&
!(retVal = function_namespace0_generated_111_finish(server, ns)) &&
!(retVal = function_namespace0_generated_110_finish(server, ns)) &&
!(retVal = function_namespace0_generated_109_finish(server, ns)) &&
!(retVal = function_namespace0_generated_108_finish(server, ns)) &&
!(retVal = function_namespace0_generated_107_finish(server, ns)) &&
!(retVal = function_namespace0_generated_106_finish(server, ns)) &&
!(retVal = function_namespace0_generated_105_finish(server, ns)) &&
!(retVal = function_namespace0_generated_104_finish(server, ns)) &&
!(retVal = function_namespace0_generated_103_finish(server, ns)) &&
!(retVal = function_namespace0_generated_102_finish(server, ns)) &&
!(retVal = function_namespace0_generated_101_finish(server, ns)) &&
!(retVal = function_namespace0_generated_100_finish(server, ns)) &&
!(retVal = function_namespace0_generated_99_finish(server, ns)) &&
!(retVal = function_namespace0_generated_98_finish(server, ns)) &&
!(retVal = function_namespace0_generated_97_finish(server, ns)) &&
!(retVal = function_namespace0_generated_96_finish(server, ns)) &&
!(retVal = function_namespace0_generated_95_finish(server, ns)) &&
!(retVal = function_namespace0_generated_94_finish(server, ns)) &&
!(retVal = function_namespace0_generated_93_finish(server, ns)) &&
!(retVal = function_namespace0_generated_92_finish(server, ns)) &&
!(retVal = function_namespace0_generated_91_finish(server, ns)) &&
!(retVal = function_namespace0_generated_90_finish(server, ns)) &&
!(retVal = function_namespace0_generated_89_finish(server, ns)) &&
!(retVal = function_namespace0_generated_88_finish(server, ns)) &&
!(retVal = function_namespace0_generated_87_finish(server, ns)) &&
!(retVal = function_namespace0_generated_86_finish(server, ns)) &&
!(retVal = function_namespace0_generated_85_finish(server, ns)) &&
!(retVal = function_namespace0_generated_84_finish(server, ns)) &&
!(retVal = function_namespace0_generated_83_finish(server, ns)) &&
!(retVal = function_namespace0_generated_82_finish(server, ns)) &&
!(retVal = function_namespace0_generated_81_finish(server, ns)) &&
!(retVal = function_namespace0_generated_80_finish(server, ns)) &&
!(retVal = function_namespace0_generated_79_finish(server, ns)) &&
!(retVal = function_namespace0_generated_78_finish(server, ns)) &&
!(retVal = function_namespace0_generated_77_finish(server, ns)) &&
!(retVal = function_namespace0_generated_76_finish(server, ns)) &&
!(retVal = function_namespace0_generated_75_finish(server, ns)) &&
!(retVal = function_namespace0_generated_74_finish(server, ns)) &&
!(retVal = function_namespace0_generated_73_finish(server, ns)) &&
!(retVal = function_namespace0_generated_72_finish(server, ns)) &&
!(retVal = function_namespace0_generated_71_finish(server, ns)) &&
!(retVal = function_namespace0_generated_70_finish(server, ns)) &&
!(retVal = function_namespace0_generated_69_finish(server, ns)) &&
!(retVal = function_namespace0_generated_68_finish(server, ns)) &&
!(retVal = function_namespace0_generated_67_finish(server, ns)) &&
!(retVal = function_namespace0_generated_66_finish(server, ns)) &&
!(retVal = function_namespace0_generated_65_finish(server, ns)) &&
!(retVal = function_namespace0_generated_64_finish(server, ns)) &&
!(retVal = function_namespace0_generated_63_finish(server, ns)) &&
!(retVal = function_namespace0_generated_62_finish(server, ns)) &&
!(retVal = function_namespace0_generated_61_finish(server, ns)) &&
!(retVal = function_namespace0_generated_60_finish(server, ns)) &&
!(retVal = function_namespace0_generated_59_finish(server, ns)) &&
!(retVal = function_namespace0_generated_58_finish(server, ns)) &&
!(retVal = function_namespace0_generated_57_finish(server, ns)) &&
!(retVal = function_namespace0_generated_56_finish(server, ns)) &&
!(retVal = function_namespace0_generated_55_finish(server, ns)) &&
!(retVal = function_namespace0_generated_54_finish(server, ns)) &&
!(retVal = function_namespace0_generated_53_finish(server, ns)) &&
!(retVal = function_namespace0_generated_52_finish(server, ns)) &&
!(retVal = function_namespace0_generated_51_finish(server, ns)) &&
!(retVal = function_namespace0_generated_50_finish(server, ns)) &&
!(retVal = function_namespace0_generated_49_finish(server, ns)) &&
!(retVal = function_namespace0_generated_48_finish(server, ns)) &&
!(retVal = function_namespace0_generated_47_finish(server, ns)) &&
!(retVal = function_namespace0_generated_46_finish(server, ns)) &&
!(retVal = function_namespace0_generated_45_finish(server, ns)) &&
!(retVal = function_namespace0_generated_44_finish(server, ns)) &&
!(retVal = function_namespace0_generated_43_finish(server, ns)) &&
!(retVal = function_namespace0_generated_42_finish(server, ns)) &&
!(retVal = function_namespace0_generated_41_finish(server, ns)) &&
!(retVal = function_namespace0_generated_40_finish(server, ns)) &&
!(retVal = function_namespace0_generated_39_finish(server, ns)) &&
!(retVal = function_namespace0_generated_38_finish(server, ns)) &&
!(retVal = function_namespace0_generated_37_finish(server, ns)) &&
!(retVal = function_namespace0_generated_36_finish(server, ns)) &&
!(retVal = function_namespace0_generated_35_finish(server, ns)) &&
!(retVal = function_namespace0_generated_34_finish(server, ns)) &&
!(retVal = function_namespace0_generated_33_finish(server, ns)) &&
!(retVal = function_namespace0_generated_32_finish(server, ns)) &&
!(retVal = function_namespace0_generated_31_finish(server, ns)) &&
!(retVal = function_namespace0_generated_30_finish(server, ns)) &&
!(retVal = function_namespace0_generated_29_finish(server, ns)) &&
!(retVal = function_namespace0_generated_28_finish(server, ns)) &&
!(retVal = function_namespace0_generated_27_finish(server, ns)) &&
!(retVal = function_namespace0_generated_26_finish(server, ns)) &&
!(retVal = function_namespace0_generated_25_finish(server, ns)) &&
!(retVal = function_namespace0_generated_24_finish(server, ns)) &&
!(retVal = function_namespace0_generated_23_finish(server, ns)) &&
!(retVal = function_namespace0_generated_22_finish(server, ns)) &&
!(retVal = function_namespace0_generated_21_finish(server, ns)) &&
!(retVal = function_namespace0_generated_20_finish(server, ns)) &&
!(retVal = function_namespace0_generated_19_finish(server, ns)) &&
!(retVal = function_namespace0_generated_18_finish(server, ns)) &&
!(retVal = function_namespace0_generated_17_finish(server, ns)) &&
!(retVal = function_namespace0_generated_16_finish(server, ns)) &&
!(retVal = function_namespace0_generated_15_finish(server, ns)) &&
!(retVal = function_namespace0_generated_14_finish(server, ns)) &&
!(retVal = function_namespace0_generated_13_finish(server, ns)) &&
!(retVal = function_namespace0_generated_12_finish(server, ns)) &&
!(retVal = function_namespace0_generated_11_finish(server, ns)) &&
!(retVal = function_namespace0_generated_10_finish(server, ns)) &&
!(retVal = function_namespace0_generated_9_finish(server, ns)) &&
!(retVal = function_namespace0_generated_8_finish(server, ns)) &&
!(retVal = function_namespace0_generated_7_finish(server, ns)) &&
!(retVal = function_namespace0_generated_6_finish(server, ns)) &&
!(retVal = function_namespace0_generated_5_finish(server, ns)) &&
!(retVal = function_namespace0_generated_4_finish(server, ns)) &&
!(retVal = function_namespace0_generated_3_finish(server, ns)) &&
!(retVal = function_namespace0_generated_2_finish(server, ns)) &&
!(retVal = function_namespace0_generated_1_finish(server, ns)) &&
!(retVal = function_namespace0_generated_0_finish(server, ns)) 
); (void)(dummy);
return retVal;
}
