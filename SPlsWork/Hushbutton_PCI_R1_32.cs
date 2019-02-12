using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Linq;
using Crestron;
using Crestron.Logos.SplusLibrary;
using Crestron.Logos.SplusObjects;
using Crestron.SimplSharp;

namespace UserModule_HUSHBUTTON_PCI_R1_32
{
    public class UserModuleClass_HUSHBUTTON_PCI_R1_32 : SplusObject
    {
        static CCriticalSection g_criticalSection = new CCriticalSection();
        
        
        
        Crestron.Logos.SplusObjects.DigitalInput DEBUG;
        Crestron.Logos.SplusObjects.DigitalInput CONNECT;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> RED_LED_ON;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> GREEN_LED_ON;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> LED_TOGGLE;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> LED_OFF;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> POLL;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> MANAGED_MODE_ON;
        InOutArray<Crestron.Logos.SplusObjects.DigitalInput> MANAGED_MODE_OFF;
        Crestron.Logos.SplusObjects.StringInput DEVICE_IP_ADDRESS;
        Crestron.Logos.SplusObjects.StringInput TCPSOCKET_TX__DOLLAR__;
        Crestron.Logos.SplusObjects.DigitalOutput CONNECT_STATUS;
        InOutArray<Crestron.Logos.SplusObjects.DigitalOutput> RED_LED_IS_ON;
        InOutArray<Crestron.Logos.SplusObjects.DigitalOutput> GREEN_LED_IS_ON;
        InOutArray<Crestron.Logos.SplusObjects.DigitalOutput> PCM_RELAY_IS_CLOSED;
        InOutArray<Crestron.Logos.SplusObjects.DigitalOutput> PRESS;
        InOutArray<Crestron.Logos.SplusObjects.DigitalOutput> MANAGED_MODE_IS_ON;
        Crestron.Logos.SplusObjects.AnalogOutput TCP_CONNECT_STATUS;
        Crestron.Logos.SplusObjects.StringOutput TCPSOCKET_RX__DOLLAR__;
        SplusTcpClient TCP_CLIENT_TCPSOCKET;
        StringParameter DEVICE_PORT;
        ushort NBUSY = 0;
        ushort NWAITINGFORACK = 0;
        short ISTATUS = 0;
        CrestronString SMSG;
        CrestronString SMSGTOPARSE;
        CrestronString SSTRING;
        CrestronString SSTRINGTOSEND;
        private void SENDCOMMAND (  SplusExecutionContext __context__ ) 
            { 
            
            __context__.SourceCodeLine = 149;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( (Functions.TestForTrue ( CONNECT_STATUS  .Value ) && Functions.TestForTrue ( Functions.Length( SSTRING ) )) ) ) && Functions.TestForTrue ( Functions.BoolToInt (NWAITINGFORACK == 0) )) ))  ) ) 
                { 
                __context__.SourceCodeLine = 151;
                NWAITINGFORACK = (ushort) ( 1 ) ; 
                __context__.SourceCodeLine = 153;
                SSTRINGTOSEND  .UpdateValue ( Functions.Remove ( "}" , SSTRING , 1)  ) ; 
                __context__.SourceCodeLine = 154;
                if ( Functions.TestForTrue  ( ( Functions.Length( SSTRINGTOSEND ))  ) ) 
                    {
                    __context__.SourceCodeLine = 155;
                    ISTATUS = (short) ( Functions.SocketSend( TCP_CLIENT_TCPSOCKET , SSTRINGTOSEND ) ) ; 
                    }
                
                __context__.SourceCodeLine = 156;
                Trace( "Hushbutton_PCI: Sent: {0} To:   {1}", SSTRINGTOSEND , DEVICE_IP_ADDRESS ) ; 
                __context__.SourceCodeLine = 157;
                if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( ISTATUS >= 0 ))  ) ) 
                    { 
                    __context__.SourceCodeLine = 159;
                    if ( Functions.TestForTrue  ( ( DEBUG  .Value)  ) ) 
                        {
                        __context__.SourceCodeLine = 160;
                        Trace( "Hushbutton_PCI: Sent: {0} To:   {1}", SSTRINGTOSEND , DEVICE_IP_ADDRESS ) ; 
                        }
                    
                    } 
                
                else 
                    {
                    __context__.SourceCodeLine = 164;
                    NWAITINGFORACK = (ushort) ( 0 ) ; 
                    }
                
                __context__.SourceCodeLine = 166;
                if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( ISTATUS < 0 ) ) && Functions.TestForTrue ( DEBUG  .Value )) ))  ) ) 
                    {
                    __context__.SourceCodeLine = 167;
                    Trace( "Hushbutton_PCI: Error Sending: {0} To: {1}", SSTRINGTOSEND , DEVICE_IP_ADDRESS ) ; 
                    }
                
                } 
            
            
            }
            
        private CrestronString HEXTOBINARY (  SplusExecutionContext __context__, ushort NINTEGER ) 
            { 
            
            __context__.SourceCodeLine = 173;
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ((int)NINTEGER);
                
                    { 
                    if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 0) ) ) ) 
                        {
                        __context__.SourceCodeLine = 175;
                        return ( "0000" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) ) ) ) 
                        {
                        __context__.SourceCodeLine = 176;
                        return ( "0001" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) ) ) ) 
                        {
                        __context__.SourceCodeLine = 177;
                        return ( "0010" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) ) ) ) 
                        {
                        __context__.SourceCodeLine = 178;
                        return ( "0011" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) ) ) ) 
                        {
                        __context__.SourceCodeLine = 179;
                        return ( "0100" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) ) ) ) 
                        {
                        __context__.SourceCodeLine = 180;
                        return ( "0101" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) ) ) ) 
                        {
                        __context__.SourceCodeLine = 181;
                        return ( "0110" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) ) ) ) 
                        {
                        __context__.SourceCodeLine = 182;
                        return ( "0111" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) ) ) ) 
                        {
                        __context__.SourceCodeLine = 183;
                        return ( "1000" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 9) ) ) ) 
                        {
                        __context__.SourceCodeLine = 184;
                        return ( "1001" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 10) ) ) ) 
                        {
                        __context__.SourceCodeLine = 185;
                        return ( "1010" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 11) ) ) ) 
                        {
                        __context__.SourceCodeLine = 186;
                        return ( "1011" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 12) ) ) ) 
                        {
                        __context__.SourceCodeLine = 187;
                        return ( "1100" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 13) ) ) ) 
                        {
                        __context__.SourceCodeLine = 188;
                        return ( "1101" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 14) ) ) ) 
                        {
                        __context__.SourceCodeLine = 189;
                        return ( "1110" ) ; 
                        }
                    
                    else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_1__ == ( 15) ) ) ) 
                        {
                        __context__.SourceCodeLine = 190;
                        return ( "1111" ) ; 
                        }
                    
                    } 
                    
                }
                
            
            
            return ""; // default return value (none specified in module)
            }
            
        private void PARSEMESSAGE (  SplusExecutionContext __context__ ) 
            { 
            ushort NINDEX = 0;
            
            CrestronString STEMP;
            STEMP  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 8, this );
            
            
            __context__.SourceCodeLine = 199;
            if ( Functions.TestForTrue  ( ( Functions.Find( "{=a" , SMSGTOPARSE ))  ) ) 
                { 
                __context__.SourceCodeLine = 201;
                STEMP  .UpdateValue ( HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 4 ) , (int)( 1 ) ) ) )) + HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 5 ) , (int)( 1 ) ) ) ))  ) ; 
                __context__.SourceCodeLine = 202;
                ushort __FN_FORSTART_VAL__1 = (ushort) ( 1 ) ;
                ushort __FN_FOREND_VAL__1 = (ushort)8; 
                int __FN_FORSTEP_VAL__1 = (int)1; 
                for ( NINDEX  = __FN_FORSTART_VAL__1; (__FN_FORSTEP_VAL__1 > 0)  ? ( (NINDEX  >= __FN_FORSTART_VAL__1) && (NINDEX  <= __FN_FOREND_VAL__1) ) : ( (NINDEX  <= __FN_FORSTART_VAL__1) && (NINDEX  >= __FN_FOREND_VAL__1) ) ; NINDEX  += (ushort)__FN_FORSTEP_VAL__1) 
                    { 
                    __context__.SourceCodeLine = 204;
                    
                        {
                        int __SPLS_TMPVAR__SWTCH_2__ = ((int)NINDEX);
                        
                            { 
                            if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 1) ) ) ) 
                                {
                                __context__.SourceCodeLine = 206;
                                RED_LED_IS_ON [ 8]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 2) ) ) ) 
                                {
                                __context__.SourceCodeLine = 207;
                                RED_LED_IS_ON [ 7]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 3) ) ) ) 
                                {
                                __context__.SourceCodeLine = 208;
                                RED_LED_IS_ON [ 6]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 4) ) ) ) 
                                {
                                __context__.SourceCodeLine = 209;
                                RED_LED_IS_ON [ 5]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 5) ) ) ) 
                                {
                                __context__.SourceCodeLine = 210;
                                RED_LED_IS_ON [ 4]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 6) ) ) ) 
                                {
                                __context__.SourceCodeLine = 211;
                                RED_LED_IS_ON [ 3]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 7) ) ) ) 
                                {
                                __context__.SourceCodeLine = 212;
                                RED_LED_IS_ON [ 2]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_2__ == ( 8) ) ) ) 
                                {
                                __context__.SourceCodeLine = 213;
                                RED_LED_IS_ON [ 1]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            } 
                            
                        }
                        
                    
                    __context__.SourceCodeLine = 202;
                    } 
                
                __context__.SourceCodeLine = 217;
                STEMP  .UpdateValue ( HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 6 ) , (int)( 1 ) ) ) )) + HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 7 ) , (int)( 1 ) ) ) ))  ) ; 
                __context__.SourceCodeLine = 218;
                ushort __FN_FORSTART_VAL__2 = (ushort) ( 1 ) ;
                ushort __FN_FOREND_VAL__2 = (ushort)8; 
                int __FN_FORSTEP_VAL__2 = (int)1; 
                for ( NINDEX  = __FN_FORSTART_VAL__2; (__FN_FORSTEP_VAL__2 > 0)  ? ( (NINDEX  >= __FN_FORSTART_VAL__2) && (NINDEX  <= __FN_FOREND_VAL__2) ) : ( (NINDEX  <= __FN_FORSTART_VAL__2) && (NINDEX  >= __FN_FOREND_VAL__2) ) ; NINDEX  += (ushort)__FN_FORSTEP_VAL__2) 
                    { 
                    __context__.SourceCodeLine = 220;
                    
                        {
                        int __SPLS_TMPVAR__SWTCH_3__ = ((int)NINDEX);
                        
                            { 
                            if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 1) ) ) ) 
                                {
                                __context__.SourceCodeLine = 222;
                                GREEN_LED_IS_ON [ 8]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 2) ) ) ) 
                                {
                                __context__.SourceCodeLine = 223;
                                GREEN_LED_IS_ON [ 7]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 3) ) ) ) 
                                {
                                __context__.SourceCodeLine = 224;
                                GREEN_LED_IS_ON [ 6]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 4) ) ) ) 
                                {
                                __context__.SourceCodeLine = 225;
                                GREEN_LED_IS_ON [ 5]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 5) ) ) ) 
                                {
                                __context__.SourceCodeLine = 226;
                                GREEN_LED_IS_ON [ 4]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 6) ) ) ) 
                                {
                                __context__.SourceCodeLine = 227;
                                GREEN_LED_IS_ON [ 3]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 7) ) ) ) 
                                {
                                __context__.SourceCodeLine = 228;
                                GREEN_LED_IS_ON [ 2]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_3__ == ( 8) ) ) ) 
                                {
                                __context__.SourceCodeLine = 229;
                                GREEN_LED_IS_ON [ 1]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            } 
                            
                        }
                        
                    
                    __context__.SourceCodeLine = 218;
                    } 
                
                __context__.SourceCodeLine = 233;
                STEMP  .UpdateValue ( HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 8 ) , (int)( 1 ) ) ) )) + HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 9 ) , (int)( 1 ) ) ) ))  ) ; 
                __context__.SourceCodeLine = 234;
                ushort __FN_FORSTART_VAL__3 = (ushort) ( 1 ) ;
                ushort __FN_FOREND_VAL__3 = (ushort)8; 
                int __FN_FORSTEP_VAL__3 = (int)1; 
                for ( NINDEX  = __FN_FORSTART_VAL__3; (__FN_FORSTEP_VAL__3 > 0)  ? ( (NINDEX  >= __FN_FORSTART_VAL__3) && (NINDEX  <= __FN_FOREND_VAL__3) ) : ( (NINDEX  <= __FN_FORSTART_VAL__3) && (NINDEX  >= __FN_FOREND_VAL__3) ) ; NINDEX  += (ushort)__FN_FORSTEP_VAL__3) 
                    { 
                    __context__.SourceCodeLine = 236;
                    
                        {
                        int __SPLS_TMPVAR__SWTCH_4__ = ((int)NINDEX);
                        
                            { 
                            if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 1) ) ) ) 
                                {
                                __context__.SourceCodeLine = 238;
                                PCM_RELAY_IS_CLOSED [ 8]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 2) ) ) ) 
                                {
                                __context__.SourceCodeLine = 239;
                                PCM_RELAY_IS_CLOSED [ 7]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 3) ) ) ) 
                                {
                                __context__.SourceCodeLine = 240;
                                PCM_RELAY_IS_CLOSED [ 6]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 4) ) ) ) 
                                {
                                __context__.SourceCodeLine = 241;
                                PCM_RELAY_IS_CLOSED [ 5]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 5) ) ) ) 
                                {
                                __context__.SourceCodeLine = 242;
                                PCM_RELAY_IS_CLOSED [ 4]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 6) ) ) ) 
                                {
                                __context__.SourceCodeLine = 243;
                                PCM_RELAY_IS_CLOSED [ 3]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 7) ) ) ) 
                                {
                                __context__.SourceCodeLine = 244;
                                PCM_RELAY_IS_CLOSED [ 2]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_4__ == ( 8) ) ) ) 
                                {
                                __context__.SourceCodeLine = 245;
                                PCM_RELAY_IS_CLOSED [ 1]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            } 
                            
                        }
                        
                    
                    __context__.SourceCodeLine = 234;
                    } 
                
                __context__.SourceCodeLine = 249;
                STEMP  .UpdateValue ( HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 10 ) , (int)( 1 ) ) ) )) + HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 11 ) , (int)( 1 ) ) ) ))  ) ; 
                __context__.SourceCodeLine = 250;
                ushort __FN_FORSTART_VAL__4 = (ushort) ( 1 ) ;
                ushort __FN_FOREND_VAL__4 = (ushort)8; 
                int __FN_FORSTEP_VAL__4 = (int)1; 
                for ( NINDEX  = __FN_FORSTART_VAL__4; (__FN_FORSTEP_VAL__4 > 0)  ? ( (NINDEX  >= __FN_FORSTART_VAL__4) && (NINDEX  <= __FN_FOREND_VAL__4) ) : ( (NINDEX  <= __FN_FORSTART_VAL__4) && (NINDEX  >= __FN_FOREND_VAL__4) ) ; NINDEX  += (ushort)__FN_FORSTEP_VAL__4) 
                    { 
                    __context__.SourceCodeLine = 252;
                    
                        {
                        int __SPLS_TMPVAR__SWTCH_5__ = ((int)NINDEX);
                        
                            { 
                            if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 1) ) ) ) 
                                {
                                __context__.SourceCodeLine = 254;
                                MANAGED_MODE_IS_ON [ 8]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 2) ) ) ) 
                                {
                                __context__.SourceCodeLine = 255;
                                MANAGED_MODE_IS_ON [ 7]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 3) ) ) ) 
                                {
                                __context__.SourceCodeLine = 256;
                                MANAGED_MODE_IS_ON [ 6]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 4) ) ) ) 
                                {
                                __context__.SourceCodeLine = 257;
                                MANAGED_MODE_IS_ON [ 5]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 5) ) ) ) 
                                {
                                __context__.SourceCodeLine = 258;
                                MANAGED_MODE_IS_ON [ 4]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 6) ) ) ) 
                                {
                                __context__.SourceCodeLine = 259;
                                MANAGED_MODE_IS_ON [ 3]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 7) ) ) ) 
                                {
                                __context__.SourceCodeLine = 260;
                                MANAGED_MODE_IS_ON [ 2]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_5__ == ( 8) ) ) ) 
                                {
                                __context__.SourceCodeLine = 261;
                                MANAGED_MODE_IS_ON [ 1]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) ) ; 
                                }
                            
                            } 
                            
                        }
                        
                    
                    __context__.SourceCodeLine = 250;
                    } 
                
                } 
            
            else 
                {
                __context__.SourceCodeLine = 266;
                if ( Functions.TestForTrue  ( ( Functions.Find( "{=s" , SMSGTOPARSE ))  ) ) 
                    { 
                    __context__.SourceCodeLine = 268;
                    STEMP  .UpdateValue ( HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 4 ) , (int)( 1 ) ) ) )) + HEXTOBINARY (  __context__ , (ushort)( Functions.HextoI( Functions.Mid( SMSGTOPARSE , (int)( 5 ) , (int)( 1 ) ) ) ))  ) ; 
                    __context__.SourceCodeLine = 269;
                    ushort __FN_FORSTART_VAL__5 = (ushort) ( 1 ) ;
                    ushort __FN_FOREND_VAL__5 = (ushort)8; 
                    int __FN_FORSTEP_VAL__5 = (int)1; 
                    for ( NINDEX  = __FN_FORSTART_VAL__5; (__FN_FORSTEP_VAL__5 > 0)  ? ( (NINDEX  >= __FN_FORSTART_VAL__5) && (NINDEX  <= __FN_FOREND_VAL__5) ) : ( (NINDEX  <= __FN_FORSTART_VAL__5) && (NINDEX  >= __FN_FOREND_VAL__5) ) ; NINDEX  += (ushort)__FN_FORSTEP_VAL__5) 
                        { 
                        __context__.SourceCodeLine = 271;
                        
                            {
                            int __SPLS_TMPVAR__SWTCH_6__ = ((int)NINDEX);
                            
                                { 
                                if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 1) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 273;
                                    PRESS [ 8]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 2) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 274;
                                    PRESS [ 7]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 3) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 275;
                                    PRESS [ 6]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 4) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 276;
                                    PRESS [ 5]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 5) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 277;
                                    PRESS [ 4]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 6) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 278;
                                    PRESS [ 3]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 7) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 279;
                                    PRESS [ 2]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                else if  ( Functions.TestForTrue  (  ( __SPLS_TMPVAR__SWTCH_6__ == ( 8) ) ) ) 
                                    {
                                    __context__.SourceCodeLine = 280;
                                    PRESS [ 1]  .Value = (ushort) ( Functions.BoolToInt (Functions.Atoi( Functions.Mid( STEMP , (int)( NINDEX ) , (int)( 1 ) ) ) == 0) ) ; 
                                    }
                                
                                } 
                                
                            }
                            
                        
                        __context__.SourceCodeLine = 269;
                        } 
                    
                    } 
                
                else 
                    { 
                    __context__.SourceCodeLine = 287;
                    if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.Find( "?" , SSTRINGTOSEND ) ) || Functions.TestForTrue ( Functions.BoolToInt (SSTRINGTOSEND == SMSGTOPARSE) )) ))  ) ) 
                        { 
                        __context__.SourceCodeLine = 289;
                        NINDEX = (ushort) ( Functions.Atoi( Functions.Mid( SMSGTOPARSE , (int)( 3 ) , (int)( 1 ) ) ) ) ; 
                        __context__.SourceCodeLine = 291;
                        RED_LED_IS_ON [ NINDEX]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( SMSGTOPARSE , (int)( 4 ) , (int)( 1 ) ) ) ) ; 
                        __context__.SourceCodeLine = 292;
                        GREEN_LED_IS_ON [ NINDEX]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( SMSGTOPARSE , (int)( 5 ) , (int)( 1 ) ) ) ) ; 
                        __context__.SourceCodeLine = 293;
                        PCM_RELAY_IS_CLOSED [ NINDEX]  .Value = (ushort) ( Functions.Atoi( Functions.Mid( SMSGTOPARSE , (int)( 6 ) , (int)( 1 ) ) ) ) ; 
                        } 
                    
                    else 
                        { 
                        __context__.SourceCodeLine = 299;
                        SSTRING  .UpdateValue ( SSTRINGTOSEND + SSTRING  ) ; 
                        } 
                    
                    } 
                
                }
            
            __context__.SourceCodeLine = 303;
            NWAITINGFORACK = (ushort) ( 0 ) ; 
            __context__.SourceCodeLine = 304;
            if ( Functions.TestForTrue  ( ( Functions.Length( SSTRING ))  ) ) 
                { 
                __context__.SourceCodeLine = 306;
                CreateWait ( "__SPLS_TMPVAR__WAITLABEL_1__" , 2 , __SPLS_TMPVAR__WAITLABEL_1___Callback ) ;
                } 
            
            
            }
            
        public void __SPLS_TMPVAR__WAITLABEL_1___CallbackFn( object stateInfo )
        {
        
            try
            {
                Wait __LocalWait__ = (Wait)stateInfo;
                SplusExecutionContext __context__ = SplusThreadStartCode(__LocalWait__);
                __LocalWait__.RemoveFromList();
                
            {
            __context__.SourceCodeLine = 307;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
            }
            catch(Exception e) { ObjectCatchHandler(e); }
            finally { ObjectFinallyHandler(); }
            
        }
        
    object CONNECT_OnPush_0 ( Object __EventInfo__ )
    
        { 
        Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
        try
        {
            SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
            
            __context__.SourceCodeLine = 315;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( Functions.Length( DEVICE_IP_ADDRESS ) > 6 ) ) && Functions.TestForTrue ( Functions.Length( DEVICE_PORT  ) )) ) ) && Functions.TestForTrue ( Functions.BoolToInt (TCP_CONNECT_STATUS  .Value != 2) )) ))  ) ) 
                { 
                __context__.SourceCodeLine = 317;
                ISTATUS = (short) ( Functions.SocketConnectClient( TCP_CLIENT_TCPSOCKET , DEVICE_IP_ADDRESS , (ushort)( Functions.Atoi( DEVICE_PORT  ) ) , (ushort)( 1 ) ) ) ; 
                __context__.SourceCodeLine = 319;
                if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( ISTATUS < 0 ) ) && Functions.TestForTrue ( DEBUG  .Value )) ))  ) ) 
                    {
                    __context__.SourceCodeLine = 320;
                    Trace( "Hushbutton_PCI: Error connecting socket to address {0} on port {1}\r\n", DEVICE_IP_ADDRESS , DEVICE_PORT ) ; 
                    }
                
                } 
            
            
            
        }
        catch(Exception e) { ObjectCatchHandler(e); }
        finally { ObjectFinallyHandler( __SignalEventArg__ ); }
        return this;
        
    }
    
object CONNECT_OnRelease_1 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        
        __context__.SourceCodeLine = 326;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( Functions.Length( DEVICE_IP_ADDRESS ) > 6 ) ) && Functions.TestForTrue ( Functions.Length( DEVICE_PORT  ) )) ))  ) ) 
            { 
            __context__.SourceCodeLine = 328;
            ISTATUS = (short) ( Functions.SocketDisconnectClient( TCP_CLIENT_TCPSOCKET ) ) ; 
            __context__.SourceCodeLine = 330;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( ISTATUS < 0 ) ) && Functions.TestForTrue ( DEBUG  .Value )) ))  ) ) 
                {
                __context__.SourceCodeLine = 331;
                Trace( "Hushbutton_PCI: Error disconnecting socket to address {0} on port {1:d}\r\n", DEVICE_IP_ADDRESS , (short)Functions.Atoi( DEVICE_PORT  )) ; 
                }
            
            } 
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object TCP_CLIENT_TCPSOCKET_OnSocketConnect_2 ( Object __Info__ )

    { 
    SocketEventInfo __SocketInfo__ = (SocketEventInfo)__Info__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SocketInfo__);
        
        __context__.SourceCodeLine = 337;
        CONNECT_STATUS  .Value = (ushort) ( 1 ) ; 
        __context__.SourceCodeLine = 339;
        if ( Functions.TestForTrue  ( ( DEBUG  .Value)  ) ) 
            {
            __context__.SourceCodeLine = 340;
            Trace( "Hushbutton_PCI: OnConnect: Connected to port {0} on address {1}\r\n", DEVICE_PORT , DEVICE_IP_ADDRESS ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SocketInfo__ ); }
    return this;
    
}

object TCP_CLIENT_TCPSOCKET_OnSocketDisconnect_3 ( Object __Info__ )

    { 
    SocketEventInfo __SocketInfo__ = (SocketEventInfo)__Info__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SocketInfo__);
        
        __context__.SourceCodeLine = 345;
        CONNECT_STATUS  .Value = (ushort) ( 0 ) ; 
        __context__.SourceCodeLine = 346;
        NWAITINGFORACK = (ushort) ( 0 ) ; 
        __context__.SourceCodeLine = 348;
        if ( Functions.TestForTrue  ( ( DEBUG  .Value)  ) ) 
            {
            __context__.SourceCodeLine = 349;
            Trace( "Hushbutton_PCI: On Disconnect: Disconnected to port {0} on address {1}\r\n", DEVICE_PORT , DEVICE_IP_ADDRESS ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SocketInfo__ ); }
    return this;
    
}

object TCP_CLIENT_TCPSOCKET_OnSocketStatus_4 ( Object __Info__ )

    { 
    SocketEventInfo __SocketInfo__ = (SocketEventInfo)__Info__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SocketInfo__);
        
        __context__.SourceCodeLine = 354;
        TCP_CONNECT_STATUS  .Value = (ushort) ( __SocketInfo__.SocketStatus ) ; 
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SocketInfo__ ); }
    return this;
    
}

object TCP_CLIENT_TCPSOCKET_OnSocketReceive_5 ( Object __Info__ )

    { 
    SocketEventInfo __SocketInfo__ = (SocketEventInfo)__Info__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SocketInfo__);
        
        __context__.SourceCodeLine = 359;
        TCPSOCKET_RX__DOLLAR__  .UpdateValue ( TCP_CLIENT_TCPSOCKET .  SocketRxBuf  ) ; 
        __context__.SourceCodeLine = 361;
        if ( Functions.TestForTrue  ( ( DEBUG  .Value)  ) ) 
            {
            __context__.SourceCodeLine = 362;
            Trace( "Hushbutton_PCI: Rx'd: {0} From:   {1}", TCP_CLIENT_TCPSOCKET .  SocketRxBuf , DEVICE_IP_ADDRESS ) ; 
            }
        
        __context__.SourceCodeLine = 364;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (Functions.Left( TCP_CLIENT_TCPSOCKET.SocketRxBuf , (int)( 4 ) ) != "\u0000"))  ) ) 
            {
            __context__.SourceCodeLine = 365;
            SMSG  .UpdateValue ( SMSG + TCP_CLIENT_TCPSOCKET .  SocketRxBuf  ) ; 
            }
        
        __context__.SourceCodeLine = 367;
        Functions.ClearBuffer ( TCP_CLIENT_TCPSOCKET .  SocketRxBuf ) ; 
        __context__.SourceCodeLine = 369;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NBUSY == 0))  ) ) 
            { 
            __context__.SourceCodeLine = 371;
            NBUSY = (ushort) ( 1 ) ; 
            __context__.SourceCodeLine = 373;
            while ( Functions.TestForTrue  ( ( Functions.Find( "}" , SMSG ))  ) ) 
                { 
                __context__.SourceCodeLine = 375;
                SMSGTOPARSE  .UpdateValue ( Functions.Remove ( "}" , SMSG )  ) ; 
                __context__.SourceCodeLine = 376;
                PARSEMESSAGE (  __context__  ) ; 
                __context__.SourceCodeLine = 373;
                } 
            
            __context__.SourceCodeLine = 379;
            NBUSY = (ushort) ( 0 ) ; 
            } 
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SocketInfo__ ); }
    return this;
    
}

object TCPSOCKET_TX__DOLLAR___OnChange_6 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        
        __context__.SourceCodeLine = 385;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (TCP_CONNECT_STATUS  .Value == 2))  ) ) 
            { 
            __context__.SourceCodeLine = 387;
            ISTATUS = (short) ( Functions.SocketSend( TCP_CLIENT_TCPSOCKET , TCPSOCKET_TX__DOLLAR__ ) ) ; 
            __context__.SourceCodeLine = 388;
            Trace( "Hushbutton_PCI: Error Sending to TCP_CLIENT_TCPSocket: {0}\r\n", TCPSOCKET_TX__DOLLAR__ ) ; 
            __context__.SourceCodeLine = 389;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( (Functions.TestForTrue ( Functions.BoolToInt ( ISTATUS < 0 ) ) && Functions.TestForTrue ( DEBUG  .Value )) ))  ) ) 
                {
                __context__.SourceCodeLine = 390;
                Trace( "Hushbutton_PCI: Error Sending to TCP_CLIENT_TCPSocket: {0}\r\n", TCPSOCKET_TX__DOLLAR__ ) ; 
                }
            
            } 
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object RED_LED_ON_OnPush_7 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 399;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 401;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            { 
            __context__.SourceCodeLine = 403;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "1001}"  ) ; 
            } 
        
        else 
            {
            __context__.SourceCodeLine = 405;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                { 
                __context__.SourceCodeLine = 407;
                SSTRING  .UpdateValue ( SSTRING + "{=aff0000ff}"  ) ; 
                } 
            
            }
        
        __context__.SourceCodeLine = 409;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 410;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object GREEN_LED_ON_OnPush_8 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 418;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 420;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            { 
            __context__.SourceCodeLine = 422;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "0111}"  ) ; 
            } 
        
        else 
            {
            __context__.SourceCodeLine = 424;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                { 
                __context__.SourceCodeLine = 426;
                SSTRING  .UpdateValue ( SSTRING + "{=a00ffffff}"  ) ; 
                } 
            
            }
        
        __context__.SourceCodeLine = 429;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 430;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object LED_TOGGLE_OnPush_9 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 438;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 440;
        if ( Functions.TestForTrue  ( ( RED_LED_IS_ON[ NINDEX ] .Value)  ) ) 
            {
            __context__.SourceCodeLine = 441;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "0111}"  ) ; 
            }
        
        else 
            {
            __context__.SourceCodeLine = 443;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "1001}"  ) ; 
            }
        
        __context__.SourceCodeLine = 445;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 446;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object LED_OFF_OnPush_10 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 454;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 456;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            {
            __context__.SourceCodeLine = 457;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "0001}"  ) ; 
            }
        
        else 
            {
            __context__.SourceCodeLine = 458;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                {
                __context__.SourceCodeLine = 459;
                SSTRING  .UpdateValue ( SSTRING + "{=a000000ff}"  ) ; 
                }
            
            }
        
        __context__.SourceCodeLine = 461;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 462;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object MANAGED_MODE_ON_OnPush_11 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 470;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 472;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            {
            __context__.SourceCodeLine = 473;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "xxx1}"  ) ; 
            }
        
        else 
            {
            __context__.SourceCodeLine = 474;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                {
                __context__.SourceCodeLine = 475;
                SSTRING  .UpdateValue ( SSTRING + "{=axxxxxxff}"  ) ; 
                }
            
            }
        
        __context__.SourceCodeLine = 477;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 478;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object MANAGED_MODE_OFF_OnPush_12 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 485;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 487;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            {
            __context__.SourceCodeLine = 488;
            SSTRING  .UpdateValue ( SSTRING + "{=" + Functions.ItoA (  (int) ( NINDEX ) ) + "xxx0}"  ) ; 
            }
        
        else 
            {
            __context__.SourceCodeLine = 489;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                {
                __context__.SourceCodeLine = 490;
                SSTRING  .UpdateValue ( SSTRING + "{=axxxxxx00}"  ) ; 
                }
            
            }
        
        __context__.SourceCodeLine = 492;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 493;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

object POLL_OnPush_13 ( Object __EventInfo__ )

    { 
    Crestron.Logos.SplusObjects.SignalEventArgs __SignalEventArg__ = (Crestron.Logos.SplusObjects.SignalEventArgs)__EventInfo__;
    try
    {
        SplusExecutionContext __context__ = SplusThreadStartCode(__SignalEventArg__);
        ushort NINDEX = 0;
        
        
        __context__.SourceCodeLine = 500;
        NINDEX = (ushort) ( Functions.GetLastModifiedArrayIndex( __SignalEventArg__ ) ) ; 
        __context__.SourceCodeLine = 501;
        Trace( "POLL nIndex: {0:d}", (short)NINDEX) ; 
        __context__.SourceCodeLine = 504;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt ( NINDEX < 9 ))  ) ) 
            { 
            __context__.SourceCodeLine = 506;
            SSTRING  .UpdateValue ( SSTRING + "{?" + Functions.ItoA (  (int) ( NINDEX ) ) + "}"  ) ; 
            } 
        
        else 
            {
            __context__.SourceCodeLine = 508;
            if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NINDEX == 9))  ) ) 
                { 
                __context__.SourceCodeLine = 510;
                SSTRING  .UpdateValue ( SSTRING + "{?a}"  ) ; 
                } 
            
            }
        
        __context__.SourceCodeLine = 513;
        if ( Functions.TestForTrue  ( ( Functions.BoolToInt (NWAITINGFORACK == 0))  ) ) 
            {
            __context__.SourceCodeLine = 514;
            SENDCOMMAND (  __context__  ) ; 
            }
        
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler( __SignalEventArg__ ); }
    return this;
    
}

public override object FunctionMain (  object __obj__ ) 
    { 
    try
    {
        SplusExecutionContext __context__ = SplusFunctionMainStartCode();
        
        __context__.SourceCodeLine = 522;
        NWAITINGFORACK = (ushort) ( 0 ) ; 
        
        
    }
    catch(Exception e) { ObjectCatchHandler(e); }
    finally { ObjectFinallyHandler(); }
    return __obj__;
    }
    

public override void LogosSplusInitialize()
{
    SocketInfo __socketinfo__ = new SocketInfo( 1, this );
    InitialParametersClass.ResolveHostName = __socketinfo__.ResolveHostName;
    _SplusNVRAM = new SplusNVRAM( this );
    SMSG  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 64, this );
    SMSGTOPARSE  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 12, this );
    SSTRING  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 1024, this );
    SSTRINGTOSEND  = new CrestronString( Crestron.Logos.SplusObjects.CrestronStringEncoding.eEncodingASCII, 24, this );
    TCP_CLIENT_TCPSOCKET  = new SplusTcpClient ( 64, this );
    
    DEBUG = new Crestron.Logos.SplusObjects.DigitalInput( DEBUG__DigitalInput__, this );
    m_DigitalInputList.Add( DEBUG__DigitalInput__, DEBUG );
    
    CONNECT = new Crestron.Logos.SplusObjects.DigitalInput( CONNECT__DigitalInput__, this );
    m_DigitalInputList.Add( CONNECT__DigitalInput__, CONNECT );
    
    RED_LED_ON = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        RED_LED_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( RED_LED_ON__DigitalInput__ + i, RED_LED_ON__DigitalInput__, this );
        m_DigitalInputList.Add( RED_LED_ON__DigitalInput__ + i, RED_LED_ON[i+1] );
    }
    
    GREEN_LED_ON = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        GREEN_LED_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( GREEN_LED_ON__DigitalInput__ + i, GREEN_LED_ON__DigitalInput__, this );
        m_DigitalInputList.Add( GREEN_LED_ON__DigitalInput__ + i, GREEN_LED_ON[i+1] );
    }
    
    LED_TOGGLE = new InOutArray<DigitalInput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        LED_TOGGLE[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( LED_TOGGLE__DigitalInput__ + i, LED_TOGGLE__DigitalInput__, this );
        m_DigitalInputList.Add( LED_TOGGLE__DigitalInput__ + i, LED_TOGGLE[i+1] );
    }
    
    LED_OFF = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        LED_OFF[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( LED_OFF__DigitalInput__ + i, LED_OFF__DigitalInput__, this );
        m_DigitalInputList.Add( LED_OFF__DigitalInput__ + i, LED_OFF[i+1] );
    }
    
    POLL = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        POLL[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( POLL__DigitalInput__ + i, POLL__DigitalInput__, this );
        m_DigitalInputList.Add( POLL__DigitalInput__ + i, POLL[i+1] );
    }
    
    MANAGED_MODE_ON = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        MANAGED_MODE_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( MANAGED_MODE_ON__DigitalInput__ + i, MANAGED_MODE_ON__DigitalInput__, this );
        m_DigitalInputList.Add( MANAGED_MODE_ON__DigitalInput__ + i, MANAGED_MODE_ON[i+1] );
    }
    
    MANAGED_MODE_OFF = new InOutArray<DigitalInput>( 9, this );
    for( uint i = 0; i < 9; i++ )
    {
        MANAGED_MODE_OFF[i+1] = new Crestron.Logos.SplusObjects.DigitalInput( MANAGED_MODE_OFF__DigitalInput__ + i, MANAGED_MODE_OFF__DigitalInput__, this );
        m_DigitalInputList.Add( MANAGED_MODE_OFF__DigitalInput__ + i, MANAGED_MODE_OFF[i+1] );
    }
    
    CONNECT_STATUS = new Crestron.Logos.SplusObjects.DigitalOutput( CONNECT_STATUS__DigitalOutput__, this );
    m_DigitalOutputList.Add( CONNECT_STATUS__DigitalOutput__, CONNECT_STATUS );
    
    RED_LED_IS_ON = new InOutArray<DigitalOutput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        RED_LED_IS_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalOutput( RED_LED_IS_ON__DigitalOutput__ + i, this );
        m_DigitalOutputList.Add( RED_LED_IS_ON__DigitalOutput__ + i, RED_LED_IS_ON[i+1] );
    }
    
    GREEN_LED_IS_ON = new InOutArray<DigitalOutput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        GREEN_LED_IS_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalOutput( GREEN_LED_IS_ON__DigitalOutput__ + i, this );
        m_DigitalOutputList.Add( GREEN_LED_IS_ON__DigitalOutput__ + i, GREEN_LED_IS_ON[i+1] );
    }
    
    PCM_RELAY_IS_CLOSED = new InOutArray<DigitalOutput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        PCM_RELAY_IS_CLOSED[i+1] = new Crestron.Logos.SplusObjects.DigitalOutput( PCM_RELAY_IS_CLOSED__DigitalOutput__ + i, this );
        m_DigitalOutputList.Add( PCM_RELAY_IS_CLOSED__DigitalOutput__ + i, PCM_RELAY_IS_CLOSED[i+1] );
    }
    
    PRESS = new InOutArray<DigitalOutput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        PRESS[i+1] = new Crestron.Logos.SplusObjects.DigitalOutput( PRESS__DigitalOutput__ + i, this );
        m_DigitalOutputList.Add( PRESS__DigitalOutput__ + i, PRESS[i+1] );
    }
    
    MANAGED_MODE_IS_ON = new InOutArray<DigitalOutput>( 8, this );
    for( uint i = 0; i < 8; i++ )
    {
        MANAGED_MODE_IS_ON[i+1] = new Crestron.Logos.SplusObjects.DigitalOutput( MANAGED_MODE_IS_ON__DigitalOutput__ + i, this );
        m_DigitalOutputList.Add( MANAGED_MODE_IS_ON__DigitalOutput__ + i, MANAGED_MODE_IS_ON[i+1] );
    }
    
    TCP_CONNECT_STATUS = new Crestron.Logos.SplusObjects.AnalogOutput( TCP_CONNECT_STATUS__AnalogSerialOutput__, this );
    m_AnalogOutputList.Add( TCP_CONNECT_STATUS__AnalogSerialOutput__, TCP_CONNECT_STATUS );
    
    DEVICE_IP_ADDRESS = new Crestron.Logos.SplusObjects.StringInput( DEVICE_IP_ADDRESS__AnalogSerialInput__, 16, this );
    m_StringInputList.Add( DEVICE_IP_ADDRESS__AnalogSerialInput__, DEVICE_IP_ADDRESS );
    
    TCPSOCKET_TX__DOLLAR__ = new Crestron.Logos.SplusObjects.StringInput( TCPSOCKET_TX__DOLLAR____AnalogSerialInput__, 64, this );
    m_StringInputList.Add( TCPSOCKET_TX__DOLLAR____AnalogSerialInput__, TCPSOCKET_TX__DOLLAR__ );
    
    TCPSOCKET_RX__DOLLAR__ = new Crestron.Logos.SplusObjects.StringOutput( TCPSOCKET_RX__DOLLAR____AnalogSerialOutput__, this );
    m_StringOutputList.Add( TCPSOCKET_RX__DOLLAR____AnalogSerialOutput__, TCPSOCKET_RX__DOLLAR__ );
    
    DEVICE_PORT = new StringParameter( DEVICE_PORT__Parameter__, this );
    m_ParameterList.Add( DEVICE_PORT__Parameter__, DEVICE_PORT );
    
    __SPLS_TMPVAR__WAITLABEL_1___Callback = new WaitFunction( __SPLS_TMPVAR__WAITLABEL_1___CallbackFn );
    
    CONNECT.OnDigitalPush.Add( new InputChangeHandlerWrapper( CONNECT_OnPush_0, false ) );
    CONNECT.OnDigitalRelease.Add( new InputChangeHandlerWrapper( CONNECT_OnRelease_1, false ) );
    TCP_CLIENT_TCPSOCKET.OnSocketConnect.Add( new SocketHandlerWrapper( TCP_CLIENT_TCPSOCKET_OnSocketConnect_2, false ) );
    TCP_CLIENT_TCPSOCKET.OnSocketDisconnect.Add( new SocketHandlerWrapper( TCP_CLIENT_TCPSOCKET_OnSocketDisconnect_3, false ) );
    TCP_CLIENT_TCPSOCKET.OnSocketStatus.Add( new SocketHandlerWrapper( TCP_CLIENT_TCPSOCKET_OnSocketStatus_4, false ) );
    TCP_CLIENT_TCPSOCKET.OnSocketReceive.Add( new SocketHandlerWrapper( TCP_CLIENT_TCPSOCKET_OnSocketReceive_5, false ) );
    TCPSOCKET_TX__DOLLAR__.OnSerialChange.Add( new InputChangeHandlerWrapper( TCPSOCKET_TX__DOLLAR___OnChange_6, false ) );
    for( uint i = 0; i < 9; i++ )
        RED_LED_ON[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( RED_LED_ON_OnPush_7, false ) );
        
    for( uint i = 0; i < 9; i++ )
        GREEN_LED_ON[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( GREEN_LED_ON_OnPush_8, false ) );
        
    for( uint i = 0; i < 8; i++ )
        LED_TOGGLE[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( LED_TOGGLE_OnPush_9, false ) );
        
    for( uint i = 0; i < 9; i++ )
        LED_OFF[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( LED_OFF_OnPush_10, false ) );
        
    for( uint i = 0; i < 9; i++ )
        MANAGED_MODE_ON[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( MANAGED_MODE_ON_OnPush_11, false ) );
        
    for( uint i = 0; i < 9; i++ )
        MANAGED_MODE_OFF[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( MANAGED_MODE_OFF_OnPush_12, false ) );
        
    for( uint i = 0; i < 9; i++ )
        POLL[i+1].OnDigitalPush.Add( new InputChangeHandlerWrapper( POLL_OnPush_13, false ) );
        
    
    _SplusNVRAM.PopulateCustomAttributeList( true );
    
    NVRAM = _SplusNVRAM;
    
}

public override void LogosSimplSharpInitialize()
{
    
    
}

public UserModuleClass_HUSHBUTTON_PCI_R1_32 ( string InstanceName, string ReferenceID, Crestron.Logos.SplusObjects.CrestronStringEncoding nEncodingType ) : base( InstanceName, ReferenceID, nEncodingType ) {}


private WaitFunction __SPLS_TMPVAR__WAITLABEL_1___Callback;


const uint DEBUG__DigitalInput__ = 0;
const uint CONNECT__DigitalInput__ = 1;
const uint RED_LED_ON__DigitalInput__ = 2;
const uint GREEN_LED_ON__DigitalInput__ = 11;
const uint LED_TOGGLE__DigitalInput__ = 20;
const uint LED_OFF__DigitalInput__ = 28;
const uint POLL__DigitalInput__ = 37;
const uint MANAGED_MODE_ON__DigitalInput__ = 46;
const uint MANAGED_MODE_OFF__DigitalInput__ = 55;
const uint DEVICE_IP_ADDRESS__AnalogSerialInput__ = 0;
const uint TCPSOCKET_TX__DOLLAR____AnalogSerialInput__ = 1;
const uint CONNECT_STATUS__DigitalOutput__ = 0;
const uint RED_LED_IS_ON__DigitalOutput__ = 1;
const uint GREEN_LED_IS_ON__DigitalOutput__ = 9;
const uint PCM_RELAY_IS_CLOSED__DigitalOutput__ = 17;
const uint PRESS__DigitalOutput__ = 25;
const uint MANAGED_MODE_IS_ON__DigitalOutput__ = 33;
const uint TCP_CONNECT_STATUS__AnalogSerialOutput__ = 0;
const uint TCPSOCKET_RX__DOLLAR____AnalogSerialOutput__ = 1;
const uint DEVICE_PORT__Parameter__ = 10;

[SplusStructAttribute(-1, true, false)]
public class SplusNVRAM : SplusStructureBase
{

    public SplusNVRAM( SplusObject __caller__ ) : base( __caller__ ) {}
    
    
}

SplusNVRAM _SplusNVRAM = null;

public class __CEvent__ : CEvent
{
    public __CEvent__() {}
    public void Close() { base.Close(); }
    public int Reset() { return base.Reset() ? 1 : 0; }
    public int Set() { return base.Set() ? 1 : 0; }
    public int Wait( int timeOutInMs ) { return base.Wait( timeOutInMs ) ? 1 : 0; }
}
public class __CMutex__ : CMutex
{
    public __CMutex__() {}
    public void Close() { base.Close(); }
    public void ReleaseMutex() { base.ReleaseMutex(); }
    public int WaitForMutex() { return base.WaitForMutex() ? 1 : 0; }
}
 public int IsNull( object obj ){ return (obj == null) ? 1 : 0; }
}


}
