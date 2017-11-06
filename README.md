# EmbedSAR by Embed21
EmbedSAR is the first open source AutoSAR implementation for ECUs. It is mainly targeting the automotive sector, but the implementation can be taken over to other secotors as well. Almost all the current AutoSAR stacks that are currently in the market use huge amount of CPU runtime, which doesn't let any free time for process the main functions of an ECU.

We believe that AutoSAR specification in itself is a good reference that all engineers can use, but EmbedSAR will give the developer 2 options:
- Follow all AutoSAR specification, which will result to high CPU usage, hence not enough free CPU / ROM / RAM usage for futher ECU functions
- Follow AutoSAR specification with some deviation, which reduces the CPU / ROM / RAM usage of the AutoSAR stack, hence provides more CPU usage for extra function that used needs to implement.

If you have any questions regarding EmbedSAR or configuration parameters, please don't hesitate to contact us at:
info@embed21.com

Mile stone 1: CAN COM Stack
- Implementing CAN Interface (CAN_IF)
- Designing a basic configuration tool for the implemented comstack
