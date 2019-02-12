#include "TypeDefs.h"
#include "Globals.h"
#include "FnctList.h"
#include "Library.h"
#include "SimplSig.h"
#include "S2_Hushbutton_PCI_R1_32.h"

FUNCTION_MAIN( S2_Hushbutton_PCI_R1_32 );
EVENT_HANDLER( S2_Hushbutton_PCI_R1_32 );
DEFINE_ENTRYPOINT( S2_Hushbutton_PCI_R1_32 );


static void S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) 
    { 
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 149 );
    if ( ((GetDigitalOutput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_CONNECT_STATUS_DIG_OUTPUT ) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  )) && (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 151 );
        Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK = 1; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 153 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,2 , "%s"  , Remove ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  , 1)  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 154 );
        if ( Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  )) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 155 );
            Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS = SocketSend( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , SOCKET_PTR( S2_Hushbutton_PCI_R1_32 , __TCP_CLIENT_TCPSOCKET ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  ); 
            }
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 156 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 36, "\xFA\xE0""Hushbutton_PCI: Sent: %s To:   %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 157 );
        if ( (Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS >= 0)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 159 );
            if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT )) 
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 160 );
                Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 36, "\xFA\xE0""Hushbutton_PCI: Sent: %s To:   %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
                }
            
            } 
        
        else 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 164 );
            Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK = 0; 
            }
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 166 );
        if ( ((Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 167 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 43, "\xFA\xE0""Hushbutton_PCI: Error Sending: %s To: %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__SENDCOMMAND:
/* Begin Free local function variables */
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
    /* End Free local function variables */
    
    }
    
static struct StringHdr_s* S2_Hushbutton_PCI_R1_32__HEXTOBINARY ( struct StringHdr_s*  __FN_DSTRET_STR__  , unsigned short __NINTEGER ) 
    { 
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "0000" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0001" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "0010" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_3__, sizeof( "0011" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_3__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_4__, sizeof( "0100" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_4__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_5__, sizeof( "0101" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_5__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_6__, sizeof( "0110" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_6__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_7__, sizeof( "0111" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_7__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_8__, sizeof( "1000" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_8__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_9__, sizeof( "1001" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_9__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_10__, sizeof( "1010" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_10__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_11__, sizeof( "1011" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_11__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_12__, sizeof( "1100" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_12__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_13__, sizeof( "1101" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_13__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_14__, sizeof( "1110" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_14__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_15__, sizeof( "1111" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_15__ );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "0000" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0001" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "0010" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_3__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_3__, "0011" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_4__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_4__, "0100" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_5__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_5__, "0101" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_6__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_6__, "0110" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_7__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_7__, "0111" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_8__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_8__, "1000" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_9__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_9__, "1001" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_10__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_10__, "1010" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_11__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_11__, "1011" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_12__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_12__, "1100" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_13__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_13__, "1101" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_14__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_14__, "1110" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_15__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_15__, "1111" );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 173 );
    
        {
        int __SPLS_TMPVAR__SWTCH_1__ = ( __NINTEGER) ;
        
            { 
            if ( __SPLS_TMPVAR__SWTCH_1__ == ( 0) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 175 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 176 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 177 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 178 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_3__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 179 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_4__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 180 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_5__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 181 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_6__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 182 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_7__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 183 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_8__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 9) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 184 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_9__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 10) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 185 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_10__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 11) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 186 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_11__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 12) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 187 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_12__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 13) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 188 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_13__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 14) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 189 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_14__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 15) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 190 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_15__ )   ) );
                goto S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY ; 
                }
            
            } 
            
        }
        
    
    
    S2_Hushbutton_PCI_R1_32_Exit__HEXTOBINARY:
/* Begin Free local function variables */
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_3__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_4__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_5__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_6__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_7__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_8__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_9__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_10__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_11__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_12__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_13__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_14__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_15__ );
    /* End Free local function variables */
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 194 );
    return __FN_DSTRET_STR__; 
    }
    
static void S2_Hushbutton_PCI_R1_32__PARSEMESSAGE ( ) 
    { 
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __STEMP, 50 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __STEMP );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=a" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    short __FN_FOREND_VAL__1; 
    short __FN_FORINIT_VAL__1; 
    short __FN_FOREND_VAL__2; 
    short __FN_FORINIT_VAL__2; 
    short __FN_FOREND_VAL__3; 
    short __FN_FORINIT_VAL__3; 
    short __FN_FOREND_VAL__4; 
    short __FN_FORINIT_VAL__4; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "{=s" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    short __FN_FOREND_VAL__5; 
    short __FN_FORINIT_VAL__5; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "?" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__2, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__2 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__3, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__3 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__4, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__4 );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __STEMP );
    INITIALIZE_LOCAL_STRING_STRUCT( __STEMP, 50 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=a" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "{=s" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "?" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__2 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__2, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__3 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__3, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__4 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__4, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 199 );
    if ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 1 , 1 )) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 201 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 4 , 1 ) )) ,  S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 5 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 202 );
        __FN_FOREND_VAL__1 = 8; 
        __FN_FORINIT_VAL__1 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__1 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__1 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__1) ; __NINDEX  += __FN_FORINIT_VAL__1) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 204 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 206 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 207 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 208 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 209 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 210 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 211 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 212 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 213 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 202 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 217 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 6 , 1 ) )) ,  S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 7 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 218 );
        __FN_FOREND_VAL__2 = 8; 
        __FN_FORINIT_VAL__2 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__2 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__2 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__2) ; __NINDEX  += __FN_FORINIT_VAL__2) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 220 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 222 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 223 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 224 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 225 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 226 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 227 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 228 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 229 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 218 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 233 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 8 , 1 ) )) ,  S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 9 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 234 );
        __FN_FOREND_VAL__3 = 8; 
        __FN_FORINIT_VAL__3 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__3 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__3 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__3) ; __NINDEX  += __FN_FORINIT_VAL__3) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 236 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 238 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 239 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 240 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 241 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 242 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 243 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 244 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 245 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 234 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 249 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 10 , 1 ) )) ,  S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 11 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 250 );
        __FN_FOREND_VAL__4 = 8; 
        __FN_FORINIT_VAL__4 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__4 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__4 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__4) ; __NINDEX  += __FN_FORINIT_VAL__4) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 252 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 254 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 255 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 256 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 257 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 258 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 259 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 260 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 261 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__MANAGED_MODE_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 250 );
            } 
        
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 266 );
        if ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 1 , 1 )) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 268 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 4 , 1 ) )) ,  S2_Hushbutton_PCI_R1_32__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 5 , 1 ) ))  )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 269 );
            __FN_FOREND_VAL__5 = 8; 
            __FN_FORINIT_VAL__5 = 1; 
            for( __NINDEX = 1; (__FN_FORINIT_VAL__5 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__5 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__5) ; __NINDEX  += __FN_FORINIT_VAL__5) 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 271 );
                
                    {
                    int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                    
                        { 
                        if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 273 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,8, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 274 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,7, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 275 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,6, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 276 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,5, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 277 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,4, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 278 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,3, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 279 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,2, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 280 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PRESS ,1, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        } 
                        
                    }
                    
                
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 269 );
                } 
            
            } 
        
        else 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 287 );
            if ( (Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  , 1 , 1 ) || (CompareStrings( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  ) , 1 ) == 0))) 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 289 );
                __NINDEX = Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 3 , 1 ) ); 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 291 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 4 , 1 ) )) ; 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 292 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__GREEN_LED_IS_ON ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 5 , 1 ) )) ; 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 293 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__PCM_RELAY_IS_CLOSED ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )  , 6 , 1 ) )) ; 
                } 
            
            else 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 299 );
                FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND  )  ,  GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   )  ; 
                FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
                } 
            
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 303 );
    Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK = 0; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 304 );
    if ( Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  )) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 306 );
        CREATE_WAIT( S2_Hushbutton_PCI_R1_32, 2, __SPLS_TMPVAR__WAITLABEL_0__ );
        
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__PARSEMESSAGE:
/* Begin Free local function variables */
    FREE_LOCAL_STRING_STRUCT( __STEMP );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__2 );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__3 );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__4 );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
    /* End Free local function variables */
    
    }
    
DEFINE_WAITEVENT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__WAITLABEL_0__ )
    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    
    
    /* End local function variable declarations */
    
    {
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 307 );
    S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
    }

S2_Hushbutton_PCI_R1_32_Exit____SPLS_TMPVAR__WAITLABEL_0__:
    
    /* Begin Free local function variables */
    /* End Free local function variables */
    RESTORE_GLOBAL_POINTERS ;
    return 0 ;
    }
DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00000 /*Connect*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 315 );
    if ( (((Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) > 6) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  )) && (GetAnalogOutput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_TCP_CONNECT_STATUS_ANALOG_OUTPUT ) != 2))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 317 );
        Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS = SocketConnectClient( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , SOCKET_PTR ( S2_Hushbutton_PCI_R1_32 ,__TCP_CLIENT_TCPSOCKET) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  , Atoi( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  ) , 1 ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 319 );
        if ( ((Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 320 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 69, "\xFA\xE0""Hushbutton_PCI: Error connecting socket to address %s on port %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_0:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00001 /*Connect*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 326 );
    if ( ((Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) > 6) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  ))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 328 );
        Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS = SocketDisconnectClient( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , SOCKET_PTR ( S2_Hushbutton_PCI_R1_32 ,__TCP_CLIENT_TCPSOCKET) ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 330 );
        if ( ((Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 331 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 72, "\xFA\xE0""Hushbutton_PCI: Error disconnecting socket to address %s on port %d\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  , (short)( Atoi( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  ) )) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_1:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00002 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 337 );
    SetDigital ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_CONNECT_STATUS_DIG_OUTPUT, 1) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 339 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 340 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 66, "\xFA\xE0""Hushbutton_PCI: OnConnect: Connected to port %s on address %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_2:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00003 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 345 );
    SetDigital ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_CONNECT_STATUS_DIG_OUTPUT, 0) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 346 );
    Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK = 0; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 348 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 349 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 73, "\xFA\xE0""Hushbutton_PCI: On Disconnect: Disconnected to port %s on address %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_3:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00004 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 354 );
    SetAnalog ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_TCP_CONNECT_STATUS_ANALOG_OUTPUT, SocketGetStatus()) ; 
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_4:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00005 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "\x00""" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 64 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 64 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "\x00""" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 64 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 64 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 359 );
    if( ObtainStringOutputSemaphore( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ) == 0 ) {
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GENERIC_STRING_OUTPUT( S2_Hushbutton_PCI_R1_32 )  ,2 , "%s"  ,   & GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) )  ; 
    SetSerial( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_TCPSOCKET_RX$_STRING_OUTPUT, GENERIC_STRING_OUTPUT( S2_Hushbutton_PCI_R1_32 ) );
    ReleaseStringOutputSemaphore( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); }
    
    ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 361 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 362 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 38, "\xFA\xE0""Hushbutton_PCI: Rx'd: %s From:   %s""\xFB", (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ), GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 364 );
    if ( (CompareStrings( Left( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) , 4 ), LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ ) , 1 ) != 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 365 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSG  )  ,    & GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSG  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 367 );
    ClearBuffer ( (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, SocketRxBuf )) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 369 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NBUSY == 0)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 371 );
        Globals->S2_Hushbutton_PCI_R1_32.__NBUSY = 1; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 373 );
        while ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSG  )  , 1 , 1 )) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 375 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,2 , "%s"  , Remove ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )   , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSG  )    , 1  )  )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 376 );
            S2_Hushbutton_PCI_R1_32__PARSEMESSAGE ( ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 373 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 379 );
        Globals->S2_Hushbutton_PCI_R1_32.__NBUSY = 0; 
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_5:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00006 /*TCPSocket_Tx$*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 385 );
    if ( (GetAnalogOutput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_TCP_CONNECT_STATUS_ANALOG_OUTPUT ) == 2)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 387 );
        Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS = SocketSend( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , SOCKET_PTR( S2_Hushbutton_PCI_R1_32 , __TCP_CLIENT_TCPSOCKET ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __TCPSOCKET_TX$  )  ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 388 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 62, "\xFA\xE0""Hushbutton_PCI: Error Sending to TCP_CLIENT_TCPSocket: %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __TCPSOCKET_TX$  )  ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 389 );
        if ( ((Globals->S2_Hushbutton_PCI_R1_32.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), __S2_Hushbutton_PCI_R1_32_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 390 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 62, "\xFA\xE0""Hushbutton_PCI: Error Sending to TCP_CLIENT_TCPSocket: %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __TCPSOCKET_TX$  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_6:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00007 /*Red_LED_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "1001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=aff0000ff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "1001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=aff0000ff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 399 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 401 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 403 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 405 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 407 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 409 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 410 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_7:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00008 /*Green_LED_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0111}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=a00ffffff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0111}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=a00ffffff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 418 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 420 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 422 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 424 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 426 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 429 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 430 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_8:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00009 /*LED_Toggle*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0111}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "1001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0111}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "1001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 438 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 440 );
    if ( GetInOutArrayElement( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), &Globals->S2_Hushbutton_PCI_R1_32.__RED_LED_IS_ON , __NINDEX  )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 441 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 443 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 445 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 446 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_9:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000A /*LED_Off*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=a000000ff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=a000000ff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 454 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 456 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 457 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 458 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 459 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 461 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 462 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_10:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000B /*Managed_Mode_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "xxx1}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=axxxxxxff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "xxx1}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=axxxxxxff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 470 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 472 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 473 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 474 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 475 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 477 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 478 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_11:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000C /*Managed_Mode_Off*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "xxx0}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=axxxxxx00}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "xxx0}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=axxxxxx00}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 485 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 487 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 488 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 489 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 490 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 492 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 493 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_12:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000D /*Poll*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{?" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{?a}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{?" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{?a}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 500 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI_R1_32 ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 501 );
    Print( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , 18, "\xFA\xE0""POLL nIndex: %d""\xFB", (short)( __NINDEX )) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 504 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 506 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 508 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 510 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 513 );
    if ( (Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 514 );
        S2_Hushbutton_PCI_R1_32__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_R1_32_Exit__Event_13:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}


    
    

/********************************************************************************
  Constructor
********************************************************************************/

/********************************************************************************
  Destructor
********************************************************************************/

/********************************************************************************
  static void ProcessDigitalEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessDigitalEvent( struct Signal_s *Signal )
{
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_CONNECT_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00000 /*Connect*/, 0 );
                
            }
            else /*Release*/
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00001 /*Connect*/, 0 );
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_RED_LED_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00007 /*Red_LED_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_GREEN_LED_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00008 /*Green_LED_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_LED_TOGGLE_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00009 /*LED_Toggle*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_LED_OFF_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000A /*LED_Off*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_POLL_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000D /*Poll*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000B /*Managed_Mode_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_OFF_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 0000C /*Managed_Mode_Off*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
                
            }
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessAnalogEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessAnalogEvent( struct Signal_s *Signal )
{
    switch ( Signal->SignalNumber )
    {
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessStringEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessStringEvent( struct Signal_s *Signal )
{
    if ( UPDATE_INPUT_STRING( S2_Hushbutton_PCI_R1_32 ) == 1 ) return ;
    
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_TCPSOCKET_TX$_STRING_INPUT :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00006 /*TCPSocket_Tx$*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessSocketConnectEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessSocketConnectEvent( struct Signal_s *Signal )
{
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00002 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessSocketDisconnectEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessSocketDisconnectEvent( struct Signal_s *Signal )
{
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00003 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessSocketReceiveEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessSocketReceiveEvent( struct Signal_s *Signal )
{
    if ( UPDATE_INPUT_STRING( S2_Hushbutton_PCI_R1_32 ) == 1 ) return ;
    
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00005 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessSocketStatusEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessSocketStatusEvent( struct Signal_s *Signal )
{
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI_R1_32, 00004 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ) ); 
            break ;
        
    }
}

/********************************************************************************
  EVENT_HANDLER( S2_Hushbutton_PCI_R1_32 )
********************************************************************************/
EVENT_HANDLER( S2_Hushbutton_PCI_R1_32 )
    {
    SAVE_GLOBAL_POINTERS ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __RED_LED_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __GREEN_LED_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __LED_TOGGLE ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __LED_OFF ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __POLL ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __MANAGED_MODE_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI_R1_32, __MANAGED_MODE_OFF ) ;
    switch ( Signal->Type )
        {
        case e_SIGNAL_TYPE_DIGITAL :
            ProcessDigitalEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_ANALOG :
            ProcessAnalogEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_STRING :
            ProcessStringEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_CONNECT :
            ProcessSocketConnectEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_DISCONNECT :
            ProcessSocketDisconnectEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_RECEIVE :
            ProcessSocketReceiveEvent( Signal );
            break ;
        case e_SIGNAL_TYPE_STATUS :
            ProcessSocketStatusEvent( Signal );
            break ;
        }
        
    RESTORE_GLOBAL_POINTERS ;
    
    }
    
/********************************************************************************
  FUNCTION_MAIN( S2_Hushbutton_PCI_R1_32 )
********************************************************************************/
FUNCTION_MAIN( S2_Hushbutton_PCI_R1_32 )
{
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    SET_INSTANCE_POINTER ( S2_Hushbutton_PCI_R1_32 );
    
    
    /* End local function variable declarations */
    
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __RED_LED_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_RED_LED_ON_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_RED_LED_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __GREEN_LED_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_GREEN_LED_ON_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_GREEN_LED_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __LED_TOGGLE, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_LED_TOGGLE_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_LED_TOGGLE_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __LED_OFF, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_LED_OFF_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_LED_OFF_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __POLL, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_POLL_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_POLL_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __MANAGED_MODE_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_ON_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __MANAGED_MODE_OFF, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_OFF_DIG_INPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_OFF_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __RED_LED_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_R1_32_RED_LED_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_R1_32_RED_LED_IS_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __GREEN_LED_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_R1_32_GREEN_LED_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_R1_32_GREEN_LED_IS_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __PCM_RELAY_IS_CLOSED, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_R1_32_PCM_RELAY_IS_CLOSED_DIG_OUTPUT, __S2_Hushbutton_PCI_R1_32_PCM_RELAY_IS_CLOSED_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __PRESS, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_R1_32_PRESS_DIG_OUTPUT, __S2_Hushbutton_PCI_R1_32_PRESS_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI_R1_32, __MANAGED_MODE_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_R1_32_MANAGED_MODE_IS_ON_ARRAY_LENGTH );
    
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS, e_INPUT_TYPE_STRING, __S2_Hushbutton_PCI_R1_32_DEVICE_IP_ADDRESS_STRING_MAX_LEN );
    REGISTER_GLOBAL_INPUT_STRING ( S2_Hushbutton_PCI_R1_32, __DEVICE_IP_ADDRESS, __S2_Hushbutton_PCI_R1_32_DEVICE_IP_ADDRESS_STRING_INPUT );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __TCPSOCKET_TX$, e_INPUT_TYPE_STRING, __S2_Hushbutton_PCI_R1_32_TCPSOCKET_TX$_STRING_MAX_LEN );
    REGISTER_GLOBAL_INPUT_STRING ( S2_Hushbutton_PCI_R1_32, __TCPSOCKET_TX$, __S2_Hushbutton_PCI_R1_32_TCPSOCKET_TX$_STRING_INPUT );
    INITIALIZE_TCP_CLIENT( S2_Hushbutton_PCI_R1_32, __TCP_CLIENT_TCPSOCKET, __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_STRING_MAX_LEN, __S2_Hushbutton_PCI_R1_32_TCP_CLIENT_TCPSOCKET_SOCKET );
    
    InitStringParamStruct ( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI_R1_32, __DEVICE_PORT ) , e_INPUT_TYPE_STRING_PARAMETER, __S2_Hushbutton_PCI_R1_32_DEVICE_PORT_STRING_PARAMETER, __S2_Hushbutton_PCI_R1_32_DEVICE_PORT_PARAM_MAX_LEN, NAME_AS_STRING( __DEVICE_PORT ) );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __SMSG, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_R1_32_SMSG_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __SMSGTOPARSE, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_R1_32_SMSGTOPARSE_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __SSTRING, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_R1_32_SSTRING_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, __SSTRINGTOSEND, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_R1_32_SSTRINGTOSEND_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI_R1_32, sGenericOutStr, e_INPUT_TYPE_NONE, GENERIC_STRING_OUTPUT_LEN );
    
    
    
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI_R1_32 ), 522 );
    Globals->S2_Hushbutton_PCI_R1_32.__NWAITINGFORACK = 0; 
    
    S2_Hushbutton_PCI_R1_32_Exit__MAIN:/* Begin Free local function variables */
    /* End Free local function variables */
    
    RESTORE_GLOBAL_POINTERS ;
    return 0 ;
    }

