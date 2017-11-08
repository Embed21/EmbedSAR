#include "CanIf.h"

/*
[SWS_CANIF_00001]

Service name: 		CanIf_Init
Syntax: 			void CanIf_Init(const CanIf_ConfigType* ConfigPtr)
Service ID[hex]:	0x01
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	ConfigPtr Pointer to configuration parameter set, used e.g. for post build parameters
Parameters (inout):	None
Parameters (out):	None
Return value:		None
Description:		This service Initializes internal and external interfaces of the CAN Interface
					for the further processing.
*/
void CanIf_Init(const CanIf_ConfigType* ConfigPtr)
{
	/*
	[SWS_CANIF_00085]:
	The service CanIf_Init() shall initialize the global variables
	and data structures of the CanIf including flags and buffers.
	*/
}

/*
[SWS_CanTrcv_91001]

Service name:		CanIf_DeInit
Syntax:				void CanIf_DeInit(void)
Service ID[hex]:	0x02
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	None
Parameters (inout):	None
Parameters (out):	None
Return value:		None
Description:		De-initializes the CanIf module.
*/
void CanIf_DeInit(void)
{
}

/*
[SWS_CANIF_00003]

Service name:		CanIf_SetControllerMode
Syntax:				Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,
						Can_ControllerStateType ControllerMode)
Service ID[hex]:	0x03
Sync/Async:			Asynchronous
Reentrancy:			Reentrant (Not for the same controller)
Parameters (in):	ControllerId Abstracted CanIf ControllerId which is assigned to a
					CAN controller, which is requested for mode transition.
					ControllerMode Requested mode transition
Parameters (inout):	None
Parameters (out):	None
Return value:		Std_ReturnType:
						E_OK: Controller mode request has been accepted
						E_NOT_OK: Controller mode request has not been accepted
Description:		This service calls the corresponding CAN Driver service for changing of
					the CAN controller mode.
*/
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId, Can_ControllerStateType ControllerMode)
{
	return E_OK;
}

/*
[SWS_CANIF_00229]
Service name:		CanIf_GetControllerMode
Syntax:				Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId,
						Can_ControllerStateType* ControllerModePtr)
Service ID[hex]:	0x04
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	ControllerId Abstracted CanIf ControllerId which is assigned to a
					CAN controller, which is requested for current operation mode.
Parameters (inout):	None
Parameters (out):	ControllerModePtr Pointer to a memory location, where the current
					mode of the CAN controller will be stored.
Return value: 		Std_ReturnType:
						E_OK: Controller mode request has been accepted.
						E_NOT_OK: Controller mode request has not been accepted.
Description:		This service calls the corresponding CAN Driver service for obtaining the
					current status of the CAN controller.
*/
Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId, Can_ControllerStateType* ControllerModePtr)
{
	return E_OK;
}

/*
[SWS_CANIF_91001]
Service name:		CanIf_GetControllerErrorState
Syntax:				Std_ReturnType CanIf_GetControllerErrorState(uint8 ControllerId,
						Can_ErrorStateType* ErrorStatePtr)
Service ID[hex]:	0x4b
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant for the same ControllerId
Parameters (in):	ControllerId Abstracted CanIf ControllerId which is assigned to a
					CAN controller, which is requested for ErrorState.
Parameters (inout):	None
Parameters (out):	ErrorStatePtr Pointer to a memory location, where the error state
					of the CAN controller will be stored.
Return value:		Std_ReturnType:
						E_OK: Error state request has been accepted.
						E_NOT_OK: Error state request has not been accepted.
Description:		This service calls the corresponding CAN Driver service for obtaining the
					error state of the CAN controller.
*/
Std_ReturnType CanIf_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType* ErrorStatePtr)
{
	return E_OK;
}

/*
[SWS_CANIF_00005]
Service name:		CanIf_Transmit
Syntax:				Std_ReturnType CanIf_Transmit(PduIdType TxPduId,
						const PduInfoType* PduInfoPtr)
Service ID[hex]:	0x49
Sync/Async:			Synchronous
Reentrancy:			Reentrant for different PduIds. Non reentrant for the same PduId.
Parameters (in):	TxPduId Identifier of the PDU to be transmitted
					PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
Parameters (inout):	None
Parameters (out):	None
Return value:		Std_ReturnType:
						E_OK: Transmit request has been accepted.
						E_NOT_OK: Transmit request has not been accepted.
Description:		Requests transmission of a PDU.
*/
Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
	return E_OK;
}

/*
[SWS_CANIF_00520]
Service name:		CanIf_CancelTransmit
Syntax:				Std_ReturnType CanIf_CancelTransmit(PduIdType TxPduId)
Service ID[hex]:	0x4a
Sync/Async:			Synchronous
Reentrancy:			Reentrant for different PduIds. Non reentrant for the same PduId.
Parameters (in):	TxPduId Identification of the PDU to be cancelled.
Parameters (inout):	None
Parameters (out):	None
Return value:		Std_ReturnType
						E_OK: Cancellation was executed successfully by	the destination module.
						E_NOT_OK: Cancellation was rejected by the destination module.
Description:		Requests cancellation of an ongoing transmission of a PDU in a lower
					layer communication module.
*/
Std_ReturnType CanIf_CancelTransmit(PduIdType TxPduId)
{
	return E_OK;
}

/*
[SWS_CANIF_00194]
Service name:		CanIf_ReadRxPduData
Syntax:				Std_ReturnType CanIf_ReadRxPduData(
						PduIdType CanIfRxSduId,
						PduInfoType* CanIfRxInfoPtr)
Service ID[hex]:	0x06
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	CanIfRxSduId Receive L-SDU handle specifying the corresponding
					CAN L-SDU ID and implicitly the CAN Driver instance
					as well as the corresponding CAN controller device.
Parameters (inout):	None
Parameters (out):	CanIfRxInfoPtr Contains the length (SduLength) of the received
					PDU, a pointer to a buffer (SduDataPtr) containing
					the PDU, and the MetaData related to this PDU.
Return value:		Std_ReturnType:
						E_OK: Request for L-SDU data has been accepted
						E_NOT_OK: No valid data has been received
Description:		This service provides the Data Length and the received data of the requested
					CanIfRxSduId to the calling upper layer.
*/
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId, PduInfoType* CanIfRxInfoPtr)
{
	return E_OK;
}

/*
[SWS_CANIF_00202]
Service name:		CanIf_ReadTxNotifStatus
Syntax:				CanIf_NotifStatusType CanIf_ReadTxNotifStatus(
						PduIdType CanIfTxSduId)
Service ID[hex]:	0x07
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	CanIfTxSduId L-SDU handle to be transmitted.
					This handle specifies the corresponding CAN LSDU
					ID and implicitly the CAN Driver instance as
					well as the corresponding CAN controller device.
Parameters (inout):	None
Parameters (out):	None
Return value:		CanIf_NotifStatusType:
						Current confirmation status of the corresponding CAN Tx L-PDU.
Description:		This service returns the confirmation status (confirmation occurred or
					not) of a specific static or dynamic CAN Tx L-PDU, requested by the
					CanIfTxSduId.
*/

CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId)
{
	return CANIF_NO_NOTIFICATION;
}

/*
[SWS_CANIF_00230]
Service name:		CanIf_ReadRxNotifStatus
Syntax:				CanIf_NotifStatusType CanIf_ReadRxNotifStatus(
						PduIdType CanIfRxSduId)
Service ID[hex]:	0x08
Sync/Async:			Synchronous
Reentrancy:			Non Reentrant
Parameters (in):	CanIfRxSduId Receive L-SDU handle specifying the corresponding
					CAN L-SDU ID and implicitly the CAN Driver instance
					as well as the corresponding CAN controller device.
Parameters (inout):	None
Parameters (out):	None
Return value:		CanIf_NotifStatusType
						Current indication status of the corresponding CAN Rx L-PDU.
Description:		This service returns the indication status (indication occurred or not) of a
					specific CAN Rx L-PDU, requested by the CanIfRxSduId.
*/
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId)
{
	
}
						
/*
[SWS_CANIF_00008] d
Service name: CanIf_SetPduMode
Syntax: Std_ReturnType CanIf_SetPduMode(
uint8 ControllerId,
CanIf_PduModeType PduModeRequest
)
Service ID[hex]: 0x09
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): ControllerId All PDUs of the own ECU connected to the corresponding
CanIf ControllerId, which is assigned to a
physical CAN controller are addressed.
PduModeRequest Requested PDU mode change
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Request for mode transition has been accepted.
E_NOT_OK: Request for mode transition has not
been accepted.
Description: This service sets the requested mode at the L-PDUs of a predefined
logical PDU channel.
*/

/*
[SWS_CANIF_00009] d
Service name: CanIf_GetPduMode
Syntax: Std_ReturnType CanIf_GetPduMode(
uint8 ControllerId,
CanIf_PduModeType* PduModePtr
)
Service ID[hex]: 0x0a
Sync/Async: Synchronous
Reentrancy: Reentrant (Not for the same channel)
Parameters (in): ControllerId All PDUs of the own ECU connected to the corresponding
CanIf ControllerId, which is assigned to a
physical CAN controller are addressed.
Parameters (inout): None
Parameters (out): PduModePtr Pointer to a memory location, where the current
mode of the logical PDU channel will be stored.
Return value: Std_ReturnType E_OK: PDU mode request has been accepted
E_NOT_OK: PDU mode request has not been accepted
Description: This service reports the current mode of a requested PDU channel.
*/

/*
[SWS_CANIF_00158] d
Service name:		CanIf_GetVersionInfo
Syntax:				void CanIf_GetVersionInfo(
						Std_VersionInfoType* VersionInfo)
Service ID[hex]:	0x0b
Sync/Async:			Synchronous
Reentrancy:			Reentrant
Parameters (in):	None
Parameters (inout):	None
Parameters (out):	VersionInfo Pointer to where to store the version information of
						this module.
Return value:		None
Description:		This service returns the version information of the called CAN Interface
					module.
*/
void CanIf_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
}


/*
[SWS_CANIF_00189] d
Service name: CanIf_SetDynamicTxId
Syntax: void CanIf_SetDynamicTxId(
PduIdType CanIfTxSduId,
Can_IdType CanId
)
Service ID[hex]: 0x0c
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): CanIfTxSduId L-SDU handle to be transmitted.
This handle specifies the corresponding CAN LSDU
ID and implicitly the CAN Driver instance as
well as the corresponding CAN controller device.
CanId Standard/Extended CAN ID of CAN L-SDU that
shall be transmitted as FD or conventional CAN
frame.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service reconfigures the corresponding CAN identifier of the requested
CAN L-PDU.
*/

/*
[SWS_CANIF_00287] d
Service name: CanIf_SetTrcvMode
Syntax: Std_ReturnType CanIf_SetTrcvMode(
uint8 TransceiverId,
CanTrcv_TrcvModeType TransceiverMode
)
Service ID[hex]: 0x0d
Sync/Async: Asynchronous
Reentrancy: Non Reentrant
Parameters (in): TransceiverId Abstracted CanIf TransceiverId, which is assigned
to a CAN transceiver, which is requested for mode
transition
TransceiverMode Requested mode transition
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Transceiver mode request has been accepted.
E_NOT_OK: Transceiver mode request has not
been accepted.
Description: This service changes the operation mode of the tansceiver TransceiverId,
via calling the corresponding CAN Transceiver Driver service.
*/

/*
[SWS_CANIF_00288] d
Service name: CanIf_GetTrcvMode
Syntax: Std_ReturnType CanIf_GetTrcvMode(
uint8 TransceiverId,
CanTrcv_TrcvModeType* TransceiverModePtr
)
Service ID[hex]: 0x0e
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): TransceiverId Abstracted CanIf TransceiverId, which is assigned
to a CAN transceiver, which is requested for current
operation mode.
Parameters (inout): None
Parameters (out): TransceiverModePtr Requested mode of requested network the
Transceiver is connected to.
Return value: Std_ReturnType E_OK: Transceiver mode request has been accepted.
E_NOT_OK: Transceiver mode request has not
been accepted.
Description: This function invokes CanTrcv_GetOpMode and updates the parameter
TransceiverModePtr with the value OpMode provided by CanTrcv.
*/

/*
Service name: CanIf_GetTrcvWakeupReason
Syntax: Std_ReturnType CanIf_GetTrcvWakeupReason(
uint8 TransceiverId,
CanTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr
)
Service ID[hex]: 0x0f
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): TransceiverId Abstracted CanIf TransceiverId, which is assigned
to a CAN transceiver, which is requested for wake
up reason.
Parameters (inout): None
Parameters (out): TrcvWuReasonPtr provided pointer to where the requested transceiver
wake up reason shall be returned
Return value: Std_ReturnType E_OK: Transceiver wake up reason request has
been accepted.
E_NOT_OK: Transceiver wake up reason request
has not been accepted.
Description: This service returns the reason for the wake up of the transceiver
TransceiverId, via calling the corresponding CAN Transceiver Driver service.
*/

/*
[SWS_CANIF_00290] d
Service name: CanIf_SetTrcvWakeupMode
Syntax: Std_ReturnType CanIf_SetTrcvWakeupMode(
uint8 TransceiverId,
CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
Service ID[hex]: 0x10
Sync/Async: Synchronous
Reentrancy: Non Reentrant
Parameters (in): TransceiverId Abstracted CanIf TransceiverId, which is assigned
to a CAN transceiver, which is requested for wake
up notification mode transition.
TrcvWakeupMode Requested transceiver wake up notification mode
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Will be returned, if the wake up notifications
state has been changed to the requested mode.
E_NOT_OK: Will be returned, if the wake up notifications
state change has failed or the parameter is
out of the allowed range. The previous state has not
been changed.
Description: This function shall call CanTrcv_SetTrcvWakeupMode.
*/

/*
[SWS_CANIF_00219] d
Service name: CanIf_CheckWakeup
Syntax: Std_ReturnType CanIf_CheckWakeup(
EcuM_WakeupSourceType WakeupSource
)
Service ID[hex]: 0x11
Sync/Async: Asynchronous
Reentrancy: Reentrant
Parameters (in): WakeupSource Source device, which initiated the wake up event:
CAN controller or CAN transceiver
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Will be returned, if the check wake up request
has been accepted
E_NOT_OK: Will be returned, if the check wake up
request has not been accepted
Description: This service checks, whether an underlying CAN driver or a CAN
transceiver driver already signals a wakeup event.
*/

/*
[SWS_CANIF_00178] d
Service name: CanIf_CheckValidation
Syntax: Std_ReturnType CanIf_CheckValidation(
EcuM_WakeupSourceType WakeupSource
)
Service ID[hex]: 0x12
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): WakeupSource Source device which initiated the wake-up event and
which has to be validated: CAN controller or CAN
transceiver
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Will be returned, if the check validation request
has been accepted.
E_NOT_OK: Will be returned, if the check validation
request has not been accepted.
Description: This service is performed to validate a previous wakeup event.
*/

/*
[SWS_CANIF_00734] d
Service name: CanIf_GetTxConfirmationState
Syntax: CanIf_NotifStatusType CanIf_GetTxConfirmationState(
uint8 ControllerId
)
Service ID[hex]: 0x19
Sync/Async: Synchronous
Reentrancy: Reentrant (Not for the same controller)
Parameters (in): ControllerId Abstracted CanIf ControllerId which is assigned to a
CAN controller
Parameters (inout): None
Parameters (out): None
Return value: CanIf_NotifStatus
Type
Combined TX confirmation status for all TX PDUs of
the CAN controller
Description: This service reports, if any TX confirmation has been done for the whole
CAN controller since the last CAN controller start.
*/

/*
[SWS_CANIF_00760] d
Service name: CanIf_ClearTrcvWufFlag
Syntax: Std_ReturnType CanIf_ClearTrcvWufFlag(
uint8 TransceiverId
)
Service ID[hex]: 0x1e
Sync/Async: Asynchronous
Reentrancy: Reentrant for different CAN transceivers
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to
the designated CAN transceiver.
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Request has been accepted
E_NOT_OK: Request has not been accepted
Description: Requests the CanIf module to clear the WUF flag of the designated CAN
transceiver.
*/

/*
[SWS_CANIF_00761] d
Service name: CanIf_CheckTrcvWakeFlag
Syntax: Std_ReturnType CanIf_CheckTrcvWakeFlag(
uint8 TransceiverId
)
Service ID[hex]: 0x1f
Sync/Async: Asynchronous
Reentrancy: Reentrant for different CAN transceivers
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to
the designated CAN transceiver.
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Request has been accepted
E_NOT_OK: Request has not been accepted
Description: Requests the CanIf module to check the Wake flag of the designated
CAN transceiver.
*/

/*
[SWS_CANIF_00867] d
Service name: CanIf_SetBaudrate
Syntax: Std_ReturnType CanIf_SetBaudrate(
uint8 ControllerId,
uint16 BaudRateConfigID
)
Service ID[hex]: 0x27
Sync/Async: Synchronous
Reentrancy: Reentrant for different ControllerIds. Non reentrant for the same ControllerId.
Parameters (in): ControllerId Abstract CanIf ControllerId which is assigned to a
CAN controller, whose baud rate shall be set.
BaudRateConfigID references a baud rate configuration by ID (see
CanControllerBaudRateConfigID)
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Service request accepted, setting of (new)
baud rate started
E_NOT_OK: Service request not accepted
Description: This service shall set the baud rate configuration of the CAN controller.
Depending on necessary baud rate modifications the controller might
have to reset.
*/

/*
[SWS_CANIF_00861] d
Service name: CanIf_SetIcomConfiguration
Syntax: Std_ReturnType CanIf_SetIcomConfiguration(
uint8 ControllerId,
IcomConfigIdType ConfigurationId
)
Service ID[hex]: 0x25
Sync/Async: Asynchronous
Reentrancy: Reentrant only for different controller Ids
Parameters (in): ControllerId Abstracted CanIf Controller Id which is assigned to
a CAN controller.
ConfigurationId Requested Configuration
Parameters (inout): None
Parameters (out): None
Return value: Std_ReturnType E_OK: Request accepted
E_NOT_OK: Request denied
Description: This service shall change the Icom Configuration of a CAN controller to
the requested one.
*/

/*
[SWS_CANIF_00883] d
Service name: CanIf_TriggerTransmit
Syntax: Std_ReturnType CanIf_TriggerTransmit(
PduIdType TxPduId,
PduInfoType* PduInfoPtr
)
Service ID[hex]: 0x41
Sync/Async: Synchronous
Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
Parameters (in): TxPduId ID of the SDU that is requested to be transmitted.
Parameters (inout): PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where
the SDU data shall be copied, and the available
buffer size in SduLengh.
On return, the service will indicate the length of the
copied SDU data in SduLength.
Parameters (out): None
Return value: Std_ReturnType E_OK: SDU has been copied and SduLength indicates
the number of copied bytes.
E_NOT_OK: No SDU data has been copied. PduInfoPtr
must not be used since it may contain a NULL
pointer or point to invalid data.
Description: Within this API, the upper layer module (called module) shall check
whether the available data fits into the buffer size reported by PduInfoPtr-
>SduLength. If it fits, it shall copy its data into the buffer provided by
PduInfoPtr->SduDataPtr and update the length of the actual copied data
in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing
PduInfoPtr.
*/

/*
[SWS_CANIF_00007] d
Service name: CanIf_TxConfirmation
Syntax: void CanIf_TxConfirmation(
PduIdType CanTxPduId
)
Service ID[hex]: 0x13
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): CanTxPduId L-PDU handle of CAN L-PDU successfully transmitted.
This ID specifies the corresponding CAN L-PDU ID
and implicitly the CAN Driver instance as well as the
corresponding CAN controller device.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service confirms a previously successfully processed transmission
of a CAN TxPDU.
*/

/*
[SWS_CANIF_00006] d
Service name: CanIf_RxIndication
Syntax: void CanIf_RxIndication(
const Can_HwType* Mailbox,
const PduInfoType* PduInfoPtr
)
Service ID[hex]: 0x14
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): Mailbox Identifies the HRH and its corresponding CAN Controller
PduInfoPtr Pointer to the received L-PDU
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates a successful reception of a received CAN Rx LPDU
to the CanIf after passing all filters and validation checks.
*/

/*
[SWS_CANIF_00218] d
Service name: CanIf_ControllerBusOff
Syntax: void CanIf_ControllerBusOff(
uint8 ControllerId
)
Service ID[hex]: 0x16
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): ControllerId Abstract CanIf ControllerId which is assigned to a
CAN controller, where a BusOff occured.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates a Controller BusOff event referring to the corresponding
CAN Controller with the abstract CanIf ControllerId.
*/

/*
[SWS_CANIF_00815] d
Service name: CanIf_ConfirmPnAvailability
Syntax: void CanIf_ConfirmPnAvailability(
uint8 TransceiverId
)
Service ID[hex]: 0x1a
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to a
CAN transceiver, which was checked for PN availability.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates that the transceiver is running in PN communication
mode referring to the corresponding CAN transceiver with the abstract
CanIf TransceiverId.
*/

/*
[SWS_CANIF_00762] d
Service name: CanIf_ClearTrcvWufFlagIndication
Syntax: void CanIf_ClearTrcvWufFlagIndication(
uint8 TransceiverId
)
Service ID[hex]: 0x20
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to a
CAN transceiver, for which this function was called.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates that the transceiver has cleared the WufFlag referring
to the corresponding CAN transceiver with the abstract CanIf
TransceiverId.
*/

/*
[SWS_CANIF_00763] d
Service name: CanIf_CheckTrcvWakeFlagIndication
Syntax: void CanIf_CheckTrcvWakeFlagIndication(
uint8 TransceiverId
)
Service ID[hex]: 0x21
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to a
CAN transceiver, for which this function was called.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates that the check of the transceiver’s wake-up flag
has been finished by the corresponding CAN transceiver with the abstract
CanIf TransceiverId. This indication is used to cope with the asynchronous
transceiver communication.
*/

/*
[SWS_CANIF_00699] d
Service name: CanIf_ControllerModeIndication
Syntax: void CanIf_ControllerModeIndication(
uint8 ControllerId,
Can_ControllerStateType ControllerMode
)
Service ID[hex]: 0x17
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): ControllerId Abstract CanIf ControllerId which is assigned to a
CAN controller, which state has been transitioned.
ControllerMode Mode to which the CAN controller transitioned
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates a controller state transition referring to the corresponding
CAN controller with the abstract CanIf ControllerId.
*/

/*
[SWS_CANIF_00764] d
Service name: CanIf_TrcvModeIndication
Syntax: void CanIf_TrcvModeIndication(
uint8 TransceiverId,
CanTrcv_TrcvModeType TransceiverMode
)
Service ID[hex]: 0x22
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): TransceiverId Abstract CanIf TransceiverId, which is assigned to a
CAN transceiver, which state has been transitioned.
TransceiverMode Mode to which the CAN transceiver transitioned
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service indicates a transceiver state transition referring to the corresponding
CAN transceiver with the abstract CanIf TransceiverId.
*/

/*
[SWS_CANIF_00862] d
Service name: CanIf_CurrentIcomConfiguration
Syntax: void CanIf_CurrentIcomConfiguration(
uint8 ControllerId,
IcomConfigIdType ConfigurationId,
IcomSwitch_ErrorType Error
)
Service ID[hex]: 0x26
Sync/Async: Synchronous
Reentrancy: Reentrant only for different controller Ids
Parameters (in): ControllerId Abstract CanIf ControllerId which is assigned to a
CAN controller, which informs about the Configuration
Id.
ConfigurationId Active Configuration Id.
Error ICOM_SWITCH_E_OK: No Error
ICOM_SWITCH_E_FAILED: Switch to requested
Configuration failed. Severe Error.
Parameters (inout): None
Parameters (out): None
Return value: None
Description: This service shall inform about the change of the Icom Configuration of
a CAN controller using the abstract CanIf ControllerId.
*/

