
#ifndef Std_TypesInterface
#define Std_TypesInterface
/*
[SWS_Std_00015]
Name:			Std_VersionInfoType
Type:			Structure
Element:		uint16		vendorID
				uint16		moduleID
				uint8		sw_major_version
				uint8		sw_minor_version
				uint8		sw_patch_version
Description:	This type shall be used to request the version of a BSW module using
				the <Modulename>_GetVersionInfo() function.
*/

typedef struct
{
	uint16	vendorID,
	uint16	moduleID,
	uint8	sw_major_version,
	uint8	sw_minor_version,
	uint8	sw_patch_version
}Std_VersionInfoType;

/*
[SWS_Std_00005]
Name:			Std_ReturnType
Kind:			Type
Derived from:	uint8
Description:	This type can be used as standard API return type which is shared between the RTE 
				and the BSW modules. It shall be defined as follows:
					typedef uint8 Std_ReturnType; 
Range:
				E_OK		0	see 8.2.1, SWS_Std_00006
				E_NOT_OK	1	see 8.2.1, SWS_Std_00006
				0x02-0x3F	2	Available to user specific errors
Variation:		--
*/

typedef enum
{
	E_OK = 0,
	E_NOT_OK = 1
}Std_ReturnType;
#endif