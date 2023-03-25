# Blinking-LED
Utalizing the peripherals of ARM Cortex v4 Architechture and tm4c123 (Tiva C) Microcontroller to build a Runtime Configurable Blinking LEDs Mcal/HAL and App layers 


<html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=utf-8">
  
  <meta name="generator" content="CherryTree">
  <link rel="stylesheet" href="res/styles4.css" type="text/css" />
</head>
<body>
<div class='page'><br/><strong><h1>Runtime Configurable LEDs using ARM Cortex v4 Architecture and tm4c123 Microcontroller</h1></strong><br /><br /><em><span style="text-decoration:underline;">Disclaimer : This project is part of &quot;Advanced Embedded Systems&quot; Nanodegree attended at Udacity and FWD program.</span></em><h2>Project Requirements:</h2><h3>1) Building Mcal/Hal layers for the microcontrollers including :</h3><br />      ◇ Implementing &quot;Mcu_HW.h&quot; file used for microcontroller hardware abstraction, includes Macros for Registers in the MCU peripheral<br />      ◇ Implementing the GPIO driver, the driver provides APIs for <code>Initializing_GPIO_Port</code> to work with some functionality using either AHB/APB, <code>Read/Write/Toggle_DIO Pins</code>, implementing  the driver API , Driver_DataTypes and user configuration .c/.h files<br />      <br />      ◇ Implementing SysTic_Timer Driver,  the driver provides APIs for <code>Intializing_Systic_Timer</code> with the required functionalities including <code>Configure_Tick_Period</code> - <code>Enable/Disable_Systic_Interrupt</code> - <code>Start/Stop_Timer</code>, implementing  the driver API , Driver_DataTypes and user configuration .c/.h files<br />      <br />      ◇ Implementing Interrupt NVIC Driver,  the driver provides APIs for <code>Intializing_Interrupt</code> at Core-Level NVIC-Level Peripheral-Level and the required Group/Subgroup Priority, implementing  the driver API , Driver_DataTypes and user configuration .c/.h files  <br /><br />      <br /><h3>2) Building Application Layer for the program :</h3> ◇ Implementing ISRs <br />      ◇ Callback Function<br />      ◇ main.c includes Drivers Initialization  <br />      ◇ User_Configs.h file for user configurations  <br /><br /><h3>3) Project testing :</h3> Testing the project operation using Keil Debugging Session and ensure ensure sucessful configurations for the Registers and variables <br /> <br /><h2>Project Idea of Operation:</h2> ⇒ Main Operation<br /><br />&gt; SysTic Timer intialized to generate periodic interrupt every 1sec<br />&gt; User specify the ON/OFF Time as function of SysTic Timer Tics (example 3secs is 3 SysTics)<br />&gt; Toggle Algorithms runs every Tic to take the decision of toggle or not<br /><br />⇒ Toggle Algorithm :<br /><br />&gt; Algorithm counts the Tics and compare the current tick with the pre-specified On/OFF Time to toggle at the end of each and reset the counter, algorithm runs at the callback function get called at SysTic Interrupt<br /><br />⇒ Configuring ON/OFF Time During Runtime<br />&gt; On/OFF time is set using static variables <br />&gt; 3 GPIO Pins are configuredto generate interrupts<br />	→ Interrupt1 used to increment Time<br />	→ Interrupt2 used to decrement Time<br />	→ Interrupt3 used to specify Increment/Decrement Operation is for ON or OFF Time according to the interrupting edge (Raising edge for ON / faling edge for decrement) <br />	<br />	 <br /><br /> <br /> <br /> <br /> <br /> <br /> <br /> </div>
</body>
</html>
