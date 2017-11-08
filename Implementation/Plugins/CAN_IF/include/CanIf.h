#include "CanIf_Types.h"

#ifndef CanIfInterface
#define CanIfInterface
/*
[SWS_CANIF_00144]
Name:			CanIf_ConfigType
Type:			Structure
Element:		implementation specific
					The contents of the initialization data structure
					are CAN interface specific
Description: 	This type defines a data structure for the post build parameters of the CAN
				interface for all underlying CAN drivers. At initialization the CanIf gets a
				pointer to a structure of this type to get access to its configuration data, which
				is necessary for initialization.
*/
struct CanIf_ConfigType
{
	/*
		[SWS_CANIF_00523] The initialization data structure for a specific
		CanIf_ConfigType shall include the definition of CanIf public parameters
		and the definition for each L-PDU/L-SDU.
	*/
}
#endif