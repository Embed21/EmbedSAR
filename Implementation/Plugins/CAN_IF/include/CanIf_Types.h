#include "Std_Types.h"
#include "Can_GeneralTypes.h"

#ifndef CanIf_TypesInterface
#define CanIf_TypesInterface
/*
[SWS_CANIF_00137]
Name:			CanIf_PduModeType
Type:			Enumeration
Range:			CANIF_OFFLINE 0x00 = 0 Transmit and receive path of
					the corresponding channel are disabled => no communication
					mode
				CANIF_TX_OFFLINE 0x01 Transmit path of the corresponding
					channel is disabled. The receive path is enabled.
				CANIF_TX_OFFLINE_ACTIVE 0x02 Transmit path of the corresponding
					channel is in offline active mode (see SWS_CANIF_00072). The
					receive path is disabled. This mode requires
					CanIfTxOfflineActiveSupport = TRUE.
				CANIF_ONLINE 0x03 Transmit and receive path of the corresponding
					channel are enabled => full operation mode
Description:	The PduMode of a channel defines its transmit or receive activity.
				Communication direction (transmission and/or reception) of the channel can
				be controlled separately or together by upper layers.
*/
typedef enum
{
	CANIF_OFFLINE			= 0,
	CANIF_TX_OFFLINE		= 1,
	CANIF_TX_OFFLINE_ACTIVE	= 2,
	CANIF_ONLINE			= 3
}CanIf_PduModeType;

/*
[SWS_CANIF_00201]
Name:			CanIf_NotifStatusType
Type:			Enumeration
Range: 			CANIF_TX_RX_NOTIFICATION: The requested Rx/Tx CAN L-PDU
					was successfully transmitted or received.
				CANIF_NO_NOTIFICATION 0x00 No transmit or receive event
					occurred for the requested L-PDU.
Description: Return value of CAN L-PDU notification status.
*/

typedef enum
{
	CANIF_NO_NOTIFICATION = 0,
	CANIF_TX_RX_NOTIFICATION
}CanIf_NotifStatusType;
#endif