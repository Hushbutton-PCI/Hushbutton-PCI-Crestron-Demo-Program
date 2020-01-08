#include "TypeDefs.h"
#include "Globals.h"
#include "FnctList.h"
#include "Library.h"
#include "SimplSig.h"
#include "S2_Hushbutton_PCI.h"

FUNCTION_MAIN( S2_Hushbutton_PCI );
EVENT_HANDLER( S2_Hushbutton_PCI );
DEFINE_ENTRYPOINT( S2_Hushbutton_PCI );


static void S2_Hushbutton_PCI__SENDCOMMAND ( ) 
    { 
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 154 );
    if ( ((GetDigitalOutput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_CONNECT_STATUS_DIG_OUTPUT ) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  )) && (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 156 );
        Globals->S2_Hushbutton_PCI.__NWAITINGFORACK = 1; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 158 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,2 , "%s"  , Remove ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  , 1)  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 159 );
        if ( Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  )) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 160 );
            Globals->S2_Hushbutton_PCI.__ISTATUS = SocketSend( INSTANCE_PTR( S2_Hushbutton_PCI ) , SOCKET_PTR( S2_Hushbutton_PCI , __TCP_CLIENT_TCPSOCKET ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  ); 
            }
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 161 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 36, "\xFA\xE0""Hushbutton_PCI: Sent: %s To:   %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 162 );
        if ( (Globals->S2_Hushbutton_PCI.__ISTATUS >= 0)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 164 );
            if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT )) 
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 165 );
                Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 36, "\xFA\xE0""Hushbutton_PCI: Sent: %s To:   %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
                }
            
            } 
        
        else 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 169 );
            Globals->S2_Hushbutton_PCI.__NWAITINGFORACK = 0; 
            }
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 171 );
        if ( ((Globals->S2_Hushbutton_PCI.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 172 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 43, "\xFA\xE0""Hushbutton_PCI: Error Sending: %s To: %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__SENDCOMMAND:
/* Begin Free local function variables */
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
    FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
    FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
    /* End Free local function variables */
    
    }
    
static struct StringHdr_s* S2_Hushbutton_PCI__HEXTOBINARY ( struct StringHdr_s*  __FN_DSTRET_STR__  , unsigned short __NINTEGER ) 
    { 
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "0000" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0001" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "0010" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_3__, sizeof( "0011" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_3__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_4__, sizeof( "0100" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_4__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_5__, sizeof( "0101" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_5__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_6__, sizeof( "0110" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_6__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_7__, sizeof( "0111" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_7__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_8__, sizeof( "1000" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_8__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_9__, sizeof( "1001" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_9__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_10__, sizeof( "1010" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_10__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_11__, sizeof( "1011" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_11__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_12__, sizeof( "1100" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_12__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_13__, sizeof( "1101" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_13__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_14__, sizeof( "1110" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_14__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_15__, sizeof( "1111" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_15__ );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "0000" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0001" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "0010" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_3__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_3__, "0011" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_4__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_4__, "0100" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_5__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_5__, "0101" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_6__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_6__, "0110" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_7__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_7__, "0111" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_8__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_8__, "1000" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_9__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_9__, "1001" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_10__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_10__, "1010" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_11__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_11__, "1011" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_12__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_12__, "1100" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_13__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_13__, "1101" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_14__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_14__, "1110" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_15__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_15__, "1111" );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 178 );
    
        {
        int __SPLS_TMPVAR__SWTCH_1__ = ( __NINTEGER) ;
        
            { 
            if ( __SPLS_TMPVAR__SWTCH_1__ == ( 0) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 180 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 181 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 182 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 183 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_3__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 184 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_4__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 185 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_5__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 186 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_6__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 187 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_7__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 188 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_8__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 9) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 189 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_9__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 10) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 190 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_10__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 11) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 191 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_11__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 12) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 192 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_12__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 13) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 193 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_13__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 14) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 194 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_14__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 15) )
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 195 );
                FormatString( INSTANCE_PTR( S2_Hushbutton_PCI ),  __FN_DSTRET_STR__, 2, "%s", (  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_15__ )   ) );
                goto S2_Hushbutton_PCI_Exit__HEXTOBINARY ; 
                }
            
            } 
            
        }
        
    
    
    S2_Hushbutton_PCI_Exit__HEXTOBINARY:
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
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 199 );
    return __FN_DSTRET_STR__; 
    }
    
static void S2_Hushbutton_PCI__PARSEMESSAGE ( ) 
    { 
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __STEMP, 50 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __STEMP );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=a" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    short __FN_FOREND_VAL__1; 
    short __FN_FORINIT_VAL__1; 
    short __FN_FOREND_VAL__2; 
    short __FN_FORINIT_VAL__2; 
    short __FN_FOREND_VAL__3; 
    short __FN_FORINIT_VAL__3; 
    short __FN_FOREND_VAL__4; 
    short __FN_FORINIT_VAL__4; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "{=s" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    short __FN_FOREND_VAL__5; 
    short __FN_FORINIT_VAL__5; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "?" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__2, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__2 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__3, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__3 );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__4, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__4 );
    
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __STEMP );
    INITIALIZE_LOCAL_STRING_STRUCT( __STEMP, 50 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=a" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "{=s" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "?" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__2 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__2, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__3 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__3, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__4 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__4, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 204 );
    if ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 1 , 1 )) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 206 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 4 , 1 ) )) ,  S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 5 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 207 );
        __FN_FOREND_VAL__1 = 8; 
        __FN_FORINIT_VAL__1 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__1 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__1 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__1) ; __NINDEX  += __FN_FORINIT_VAL__1) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 209 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 211 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 212 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 213 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 214 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 215 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 216 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 217 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 218 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 207 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 222 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 6 , 1 ) )) ,  S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 7 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 223 );
        __FN_FOREND_VAL__2 = 8; 
        __FN_FORINIT_VAL__2 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__2 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__2 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__2) ; __NINDEX  += __FN_FORINIT_VAL__2) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 225 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 227 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 228 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 229 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 230 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 231 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 232 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 233 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 234 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 223 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 238 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 8 , 1 ) )) ,  S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 9 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 239 );
        __FN_FOREND_VAL__3 = 8; 
        __FN_FORINIT_VAL__3 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__3 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__3 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__3) ; __NINDEX  += __FN_FORINIT_VAL__3) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 241 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 243 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 244 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 245 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 246 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 247 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 248 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 249 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 250 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 239 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 254 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 10 , 1 ) )) ,  S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 11 , 1 ) ))  )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 255 );
        __FN_FOREND_VAL__4 = 8; 
        __FN_FORINIT_VAL__4 = 1; 
        for( __NINDEX = 1; (__FN_FORINIT_VAL__4 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__4 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__4) ; __NINDEX  += __FN_FORINIT_VAL__4) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 257 );
            
                {
                int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                
                    { 
                    if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 259 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,8, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 260 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,7, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 261 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,6, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 262 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,5, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 263 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,4, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 264 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,3, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 265 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,2, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                        {
                        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 266 );
                        SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__MANAGED_MODE_IS_ON ,1, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) )) ; 
                        }
                    
                    } 
                    
                }
                
            
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 255 );
            } 
        
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 271 );
        if ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 1 , 1 )) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 273 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__4 )    ,4 , "%s%s"  , S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__1 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 4 , 1 ) )) ,  S2_Hushbutton_PCI__HEXTOBINARY (  LOCAL_STRING_STRUCT( __FN_DST_STR__2 )    , hextoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__3 )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 5 , 1 ) ))  )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __STEMP  )   ,2 , "%s"  , __FN_DST_STR__4 ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 274 );
            __FN_FOREND_VAL__5 = 8; 
            __FN_FORINIT_VAL__5 = 1; 
            for( __NINDEX = 1; (__FN_FORINIT_VAL__5 > 0)  ? ((short)__NINDEX  <= __FN_FOREND_VAL__5 ) : ((short)__NINDEX  >= __FN_FOREND_VAL__5) ; __NINDEX  += __FN_FORINIT_VAL__5) 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 276 );
                
                    {
                    int __SPLS_TMPVAR__SWTCH_1__ = ( __NINDEX) ;
                    
                        { 
                        if ( __SPLS_TMPVAR__SWTCH_1__ == ( 1) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 278 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,8, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 2) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 279 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,7, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 3) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 280 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,6, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 4) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 281 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,5, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 5) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 282 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,4, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 6) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 283 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,3, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 7) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 284 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,2, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        else if ( __SPLS_TMPVAR__SWTCH_1__ == ( 8) )
                            {
                            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 285 );
                            SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PRESS ,1, (Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , LOCAL_STRING_STRUCT( __STEMP  )  , __NINDEX , 1 ) ) == 0)) ; 
                            }
                        
                        } 
                        
                    }
                    
                
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 274 );
                } 
            
            } 
        
        else 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 292 );
            if ( (Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  , 1 , 1 ) || (CompareStrings( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  ) , 1 ) == 0))) 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 294 );
                __NINDEX = Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 3 , 1 ) ); 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 296 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 4 , 1 ) )) ; 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 297 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__GREEN_LED_IS_ON ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 5 , 1 ) )) ; 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 298 );
                SetOutputArrayElement ( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__PCM_RELAY_IS_CLOSED ,__NINDEX, Atoi( Mid( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )  , 6 , 1 ) )) ; 
                } 
            
            else 
                { 
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 304 );
                if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT )) 
                    {
                    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 305 );
                    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRINGTOSEND  )  ,  GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   )  ; 
                    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
                    }
                
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 306 );
                Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 16, "\xFA\xE0""Resending: %s""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ) ; 
                } 
            
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 310 );
    Globals->S2_Hushbutton_PCI.__NWAITINGFORACK = 0; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 311 );
    if ( Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  )) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 313 );
        CREATE_WAIT( S2_Hushbutton_PCI, 2, __SPLS_TMPVAR__WAITLABEL_0__ );
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__PARSEMESSAGE:
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
    
DEFINE_WAITEVENT( S2_Hushbutton_PCI, __SPLS_TMPVAR__WAITLABEL_0__ )
    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    
    
    /* End local function variable declarations */
    
    {
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 314 );
    S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
    }

S2_Hushbutton_PCI_Exit____SPLS_TMPVAR__WAITLABEL_0__:
    
    /* Begin Free local function variables */
    /* End Free local function variables */
    RESTORE_GLOBAL_POINTERS ;
    return 0 ;
    }
DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00000 /*Connect*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 322 );
    if ( (((Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) > 6) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  )) && (GetAnalogOutput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_TCP_CONNECT_STATUS_ANALOG_OUTPUT ) != 2))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 324 );
        Globals->S2_Hushbutton_PCI.__ISTATUS = SocketConnectClient( INSTANCE_PTR( S2_Hushbutton_PCI ) , SOCKET_PTR ( S2_Hushbutton_PCI ,__TCP_CLIENT_TCPSOCKET) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  , Atoi( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  ) , 1 ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 326 );
        if ( ((Globals->S2_Hushbutton_PCI.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 327 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 69, "\xFA\xE0""Hushbutton_PCI: Error connecting socket to address %s on port %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__Event_0:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00001 /*Connect*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 333 );
    if ( ((Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) > 6) && Len( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  ))) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 335 );
        Globals->S2_Hushbutton_PCI.__ISTATUS = SocketDisconnectClient( INSTANCE_PTR( S2_Hushbutton_PCI ) , SOCKET_PTR ( S2_Hushbutton_PCI ,__TCP_CLIENT_TCPSOCKET) ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 337 );
        if ( ((Globals->S2_Hushbutton_PCI.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 338 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 72, "\xFA\xE0""Hushbutton_PCI: Error disconnecting socket to address %s on port %d\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  , (short)( Atoi( GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  ) )) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__Event_1:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00002 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{?a}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "{?s}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{?a}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "{?s}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 344 );
    SetDigital ( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_CONNECT_STATUS_DIG_OUTPUT, 1) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 345 );
    Globals->S2_Hushbutton_PCI.__NHEARTBEAT_ACKNOWLEDGED = 1; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 347 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 348 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 66, "\xFA\xE0""Hushbutton_PCI: OnConnect: Connected to port %s on address %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 350 );
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )    )  ; 
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 351 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 352 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 354 );
    Delay ( 20) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 355 );
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 356 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 357 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_2:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00003 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 362 );
    SetDigital ( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_CONNECT_STATUS_DIG_OUTPUT, 0) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 363 );
    Globals->S2_Hushbutton_PCI.__NWAITINGFORACK = 0; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 365 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 366 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 73, "\xFA\xE0""Hushbutton_PCI: On Disconnect: Disconnected to port %s on address %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT  )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_3:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00004 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 371 );
    SetAnalog ( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_TCP_CONNECT_STATUS_ANALOG_OUTPUT, SocketGetStatus()) ; 
    
    S2_Hushbutton_PCI_Exit__Event_4:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00005 /*TCP_CLIENT_TCPSocket*/ )

    {
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "\x00""" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 64 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 64 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "\x00""" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 64 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 64 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 376 );
    Globals->S2_Hushbutton_PCI.__NHEARTBEAT_ACKNOWLEDGED = 1; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 377 );
    if( ObtainStringOutputSemaphore( INSTANCE_PTR( S2_Hushbutton_PCI ) ) == 0 ) {
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GENERIC_STRING_OUTPUT( S2_Hushbutton_PCI )  ,2 , "%s"  ,   & GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) )  ; 
    SetSerial( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_TCPSOCKET_RX$_STRING_OUTPUT, GENERIC_STRING_OUTPUT( S2_Hushbutton_PCI ) );
    ReleaseStringOutputSemaphore( INSTANCE_PTR( S2_Hushbutton_PCI ) ); }
    
    ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 379 );
    if ( GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 380 );
        Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 38, "\xFA\xE0""Hushbutton_PCI: Rx'd: %s From:   %s""\xFB", (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ), GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS  )  ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 382 );
    if ( (CompareStrings( Left( INSTANCE_PTR( S2_Hushbutton_PCI ) , LOCAL_STRING_STRUCT( __FN_DST_STR__ )  , (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) , 4 ), LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ ) , 1 ) != 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 383 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSG  )  ,    & GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, SocketRxBuf ) )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSG  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 385 );
    ClearBuffer ( (struct StringHdr_s* )& GLOBAL_STRUCT_FIELD( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, SocketRxBuf )) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 387 );
    if ( (Globals->S2_Hushbutton_PCI.__NBUSY == 0)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 389 );
        Globals->S2_Hushbutton_PCI.__NBUSY = 1; 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 391 );
        while ( Find( LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSG  )  , 1 , 1 )) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 393 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,2 , "%s"  , Remove ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,  LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )   , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSG  )    , 1  )  )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SMSGTOPARSE  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 394 );
            S2_Hushbutton_PCI__PARSEMESSAGE ( ) ; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 391 );
            } 
        
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 397 );
        Globals->S2_Hushbutton_PCI.__NBUSY = 0; 
        } 
    
    
    S2_Hushbutton_PCI_Exit__Event_5:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00006 /*TCPSocket_Tx$*/ )

    {
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 403 );
    if ( (GetAnalogOutput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_TCP_CONNECT_STATUS_ANALOG_OUTPUT ) == 2)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 405 );
        Globals->S2_Hushbutton_PCI.__ISTATUS = SocketSend( INSTANCE_PTR( S2_Hushbutton_PCI ) , SOCKET_PTR( S2_Hushbutton_PCI , __TCP_CLIENT_TCPSOCKET ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __TCPSOCKET_TX$  )  ); 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 406 );
        if ( ((Globals->S2_Hushbutton_PCI.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT ))) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 407 );
            Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 62, "\xFA\xE0""Hushbutton_PCI: Error Sending to TCP_CLIENT_TCPSocket: %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __TCPSOCKET_TX$  )  ) ; 
            }
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__Event_6:
    /* Begin Free local function variables */
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00007 /*Red_LED_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "1001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=aff0000ff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "1001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=aff0000ff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 416 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 418 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 420 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 422 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 424 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 426 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 427 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_7:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00008 /*Green_LED_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0111}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=a00ffffff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0111}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=a00ffffff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 435 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 437 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 439 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 441 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 443 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 446 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 447 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_8:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 00009 /*LED_Toggle*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0111}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "1001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0111}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "1001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 455 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 457 );
    if ( GetInOutArrayElement( INSTANCE_PTR( S2_Hushbutton_PCI ), &Globals->S2_Hushbutton_PCI.__RED_LED_IS_ON , __NINDEX  )) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 458 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 460 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 462 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 463 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_9:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000A /*LED_Off*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "0001}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=a000000ff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "0001}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=a000000ff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 471 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 473 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 474 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 475 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 476 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 478 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 479 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_10:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000B /*Managed_Mode_On*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "xxx1}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=axxxxxxff}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "xxx1}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=axxxxxxff}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 487 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 489 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 490 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 491 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 492 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 494 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 495 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_11:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000C /*Managed_Mode_Off*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{=" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "xxx0}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{=axxxxxx00}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{=" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "xxx0}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{=axxxxxx00}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 502 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 504 );
    if ( (__NINDEX < 9)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 505 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        }
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 506 );
        if ( (__NINDEX == 9)) 
            {
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 507 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            }
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 509 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 510 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_12:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000D /*Poll_Leds*/ )

    {
    /* Begin local function variable declarations */
    
    unsigned short  __NINDEX; 
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{?" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__, sizeof( "}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__, sizeof( "{?a}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{?" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_1__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__, "}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_2__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__, "{?a}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__1 );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__1, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 517 );
    __NINDEX = GetLocalLastModifiedArrayIndex ( S2_Hushbutton_PCI ); 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 518 );
    Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 23, "\xFA\xE0""Poll_Leds nIndex: %d""\xFB", (short)( __NINDEX )) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 521 );
    if ( (__NINDEX < 9)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 523 );
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__1 )    ,8 , "%s%s%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )   ,  Itoa ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    , __NINDEX) ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ )    )  ; 
        FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__1 ) ; 
        } 
    
    else 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 525 );
        if ( (__NINDEX == 9)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 527 );
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ )    )  ; 
            FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
            } 
        
        }
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 530 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 531 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_13:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_1__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__1 );
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_2__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000E /*Poll_Presses*/ )

    {
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{?s}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__, 1024 );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{?s}" );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __FN_DST_STR__ );
    INITIALIZE_LOCAL_STRING_STRUCT( __FN_DST_STR__, 1024 );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 537 );
    Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 15, "\xFA\xE0""Poll_Presses""\xFB") ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 538 );
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) ,  LOCAL_STRING_STRUCT( __FN_DST_STR__ )    ,4 , "%s%s"  , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )  ,   LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )    )  ; 
    FormatString ( INSTANCE_PTR( S2_Hushbutton_PCI ) , GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __SSTRING  )   ,2 , "%s"  , __FN_DST_STR__ ) ; 
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 539 );
    if ( (Globals->S2_Hushbutton_PCI.__NWAITINGFORACK == 0)) 
        {
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 540 );
        S2_Hushbutton_PCI__SENDCOMMAND ( ) ; 
        }
    
    
    S2_Hushbutton_PCI_Exit__Event_14:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
FREE_LOCAL_STRING_STRUCT( __FN_DST_STR__ );
/* End Free local function variables */
RESTORE_GLOBAL_POINTERS ;

}

DEFINE_INDEPENDENT_EVENTHANDLER( S2_Hushbutton_PCI, 0000F /*Heartbeat*/ )

    {
    /* Begin local function variable declarations */
    
    CREATE_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__, sizeof( "{?a}" ) );
    DECLARE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    
    SAVE_GLOBAL_POINTERS ;
    CheckStack( INSTANCE_PTR( S2_Hushbutton_PCI ) );
    
    ALLOCATE_LOCAL_STRING_STRUCT( S2_Hushbutton_PCI, __SPLS_TMPVAR__LOCALSTR_0__ );
    SET_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__, "{?a}" );
    
    
    /* End local function variable declarations */
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 545 );
    if ( (GetDigitalOutput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_CONNECT_STATUS_DIG_OUTPUT ) == 1)) 
        { 
        UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 547 );
        if ( (Globals->S2_Hushbutton_PCI.__NHEARTBEAT_ACKNOWLEDGED == 1)) 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 549 );
            Globals->S2_Hushbutton_PCI.__NHEARTBEAT_ACKNOWLEDGED = 0; 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 550 );
            Globals->S2_Hushbutton_PCI.__ISTATUS = SocketSend( INSTANCE_PTR( S2_Hushbutton_PCI ) , SOCKET_PTR( S2_Hushbutton_PCI , __TCP_CLIENT_TCPSOCKET ) , LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ )  ); 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 551 );
            if ( ((Globals->S2_Hushbutton_PCI.__ISTATUS < 0) && GetDigitalInput( INSTANCE_PTR( S2_Hushbutton_PCI ), __S2_Hushbutton_PCI_DEBUG_DIG_INPUT ))) 
                {
                UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 552 );
                Print( INSTANCE_PTR( S2_Hushbutton_PCI ) , 72, "\xFA\xE0""Hushbutton_PCI: Error Sending Heartbeat to TCP_CLIENT_TCPSocket: %s\r\n""\xFB", GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __TCPSOCKET_TX$  )  ) ; 
                }
            
            } 
        
        else 
            { 
            UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 556 );
            Pulse ( INSTANCE_PTR( S2_Hushbutton_PCI ) , 10, __S2_Hushbutton_PCI_HEARTBEAT_TIMEOUT_DIG_OUTPUT ) ; 
            } 
        
        } 
    
    
    S2_Hushbutton_PCI_Exit__Event_15:
    /* Begin Free local function variables */
FREE_LOCAL_STRING_STRUCT( __SPLS_TMPVAR__LOCALSTR_0__ );
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
        case __S2_Hushbutton_PCI_CONNECT_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00000 /*Connect*/, 0 );
                
            }
            else /*Release*/
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00001 /*Connect*/, 0 );
                
            }
            break;
            
        case __S2_Hushbutton_PCI_HEARTBEAT_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000F /*Heartbeat*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_POLL_PRESSES_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000E /*Poll_Presses*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_RED_LED_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00007 /*Red_LED_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_GREEN_LED_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00008 /*Green_LED_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_LED_TOGGLE_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00009 /*LED_Toggle*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_LED_OFF_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000A /*LED_Off*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_POLL_LEDS_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000D /*Poll_Leds*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_MANAGED_MODE_ON_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000B /*Managed_Mode_On*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        case __S2_Hushbutton_PCI_MANAGED_MODE_OFF_DIG_INPUT :
            if ( Signal->Value /*Push*/ )
            {
                SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 0000C /*Managed_Mode_Off*/, 0 );
                
            }
            else /*Release*/
            {
                SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
                
            }
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
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
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessStringEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessStringEvent( struct Signal_s *Signal )
{
    if ( UPDATE_INPUT_STRING( S2_Hushbutton_PCI ) == 1 ) return ;
    
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_TCPSOCKET_TX$_STRING_INPUT :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00006 /*TCPSocket_Tx$*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
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
        case __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00002 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
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
        case __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00003 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
            break ;
        
    }
}

/********************************************************************************
  static void ProcessSocketReceiveEvent( struct Signal_s *Signal )
********************************************************************************/
static void ProcessSocketReceiveEvent( struct Signal_s *Signal )
{
    if ( UPDATE_INPUT_STRING( S2_Hushbutton_PCI ) == 1 ) return ;
    
    switch ( Signal->SignalNumber )
    {
        case __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00005 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
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
        case __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_SOCKET :
            SAFESPAWN_EVENTHANDLER( S2_Hushbutton_PCI, 00004 /*TCP_CLIENT_TCPSocket*/, 0 );
            break;
            
        default :
            SetSymbolEventStart ( INSTANCE_PTR( S2_Hushbutton_PCI ) ); 
            break ;
        
    }
}

/********************************************************************************
  EVENT_HANDLER( S2_Hushbutton_PCI )
********************************************************************************/
EVENT_HANDLER( S2_Hushbutton_PCI )
    {
    SAVE_GLOBAL_POINTERS ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __RED_LED_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __GREEN_LED_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __LED_TOGGLE ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __LED_OFF ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __POLL_LEDS ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __MANAGED_MODE_ON ) ;
    CHECK_INPUT_ARRAY ( S2_Hushbutton_PCI, __MANAGED_MODE_OFF ) ;
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
  FUNCTION_MAIN( S2_Hushbutton_PCI )
********************************************************************************/
FUNCTION_MAIN( S2_Hushbutton_PCI )
{
    /* Begin local function variable declarations */
    
    SAVE_GLOBAL_POINTERS ;
    SET_INSTANCE_POINTER ( S2_Hushbutton_PCI );
    
    
    /* End local function variable declarations */
    
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __RED_LED_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_RED_LED_ON_DIG_INPUT, __S2_Hushbutton_PCI_RED_LED_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __GREEN_LED_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_GREEN_LED_ON_DIG_INPUT, __S2_Hushbutton_PCI_GREEN_LED_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __LED_TOGGLE, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_LED_TOGGLE_DIG_INPUT, __S2_Hushbutton_PCI_LED_TOGGLE_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __LED_OFF, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_LED_OFF_DIG_INPUT, __S2_Hushbutton_PCI_LED_OFF_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __POLL_LEDS, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_POLL_LEDS_DIG_INPUT, __S2_Hushbutton_PCI_POLL_LEDS_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __MANAGED_MODE_ON, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_MANAGED_MODE_ON_DIG_INPUT, __S2_Hushbutton_PCI_MANAGED_MODE_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __MANAGED_MODE_OFF, IO_TYPE_DIGITAL_INPUT, __S2_Hushbutton_PCI_MANAGED_MODE_OFF_DIG_INPUT, __S2_Hushbutton_PCI_MANAGED_MODE_OFF_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __RED_LED_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_RED_LED_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_RED_LED_IS_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __GREEN_LED_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_GREEN_LED_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_GREEN_LED_IS_ON_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __PCM_RELAY_IS_CLOSED, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_PCM_RELAY_IS_CLOSED_DIG_OUTPUT, __S2_Hushbutton_PCI_PCM_RELAY_IS_CLOSED_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __PRESS, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_PRESS_DIG_OUTPUT, __S2_Hushbutton_PCI_PRESS_ARRAY_LENGTH );
    INITIALIZE_IO_ARRAY ( S2_Hushbutton_PCI, __MANAGED_MODE_IS_ON, IO_TYPE_DIGITAL_OUTPUT, __S2_Hushbutton_PCI_MANAGED_MODE_IS_ON_DIG_OUTPUT, __S2_Hushbutton_PCI_MANAGED_MODE_IS_ON_ARRAY_LENGTH );
    
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS, e_INPUT_TYPE_STRING, __S2_Hushbutton_PCI_DEVICE_IP_ADDRESS_STRING_MAX_LEN );
    REGISTER_GLOBAL_INPUT_STRING ( S2_Hushbutton_PCI, __DEVICE_IP_ADDRESS, __S2_Hushbutton_PCI_DEVICE_IP_ADDRESS_STRING_INPUT );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __TCPSOCKET_TX$, e_INPUT_TYPE_STRING, __S2_Hushbutton_PCI_TCPSOCKET_TX$_STRING_MAX_LEN );
    REGISTER_GLOBAL_INPUT_STRING ( S2_Hushbutton_PCI, __TCPSOCKET_TX$, __S2_Hushbutton_PCI_TCPSOCKET_TX$_STRING_INPUT );
    INITIALIZE_TCP_CLIENT( S2_Hushbutton_PCI, __TCP_CLIENT_TCPSOCKET, __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_STRING_MAX_LEN, __S2_Hushbutton_PCI_TCP_CLIENT_TCPSOCKET_SOCKET );
    
    InitStringParamStruct ( INSTANCE_PTR( S2_Hushbutton_PCI ), GLOBAL_STRING_STRUCT( S2_Hushbutton_PCI, __DEVICE_PORT ) , e_INPUT_TYPE_STRING_PARAMETER, __S2_Hushbutton_PCI_DEVICE_PORT_STRING_PARAMETER, __S2_Hushbutton_PCI_DEVICE_PORT_PARAM_MAX_LEN, NAME_AS_STRING( __DEVICE_PORT ) );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __SMSG, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_SMSG_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __SMSGTOPARSE, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_SMSGTOPARSE_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __SSTRING, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_SSTRING_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, __SSTRINGTOSEND, e_INPUT_TYPE_NONE, __S2_Hushbutton_PCI_SSTRINGTOSEND_STRING_MAX_LEN );
    INITIALIZE_GLOBAL_STRING_STRUCT ( S2_Hushbutton_PCI, sGenericOutStr, e_INPUT_TYPE_NONE, GENERIC_STRING_OUTPUT_LEN );
    
    
    
    
    
    UpdateSourceCodeLine( INSTANCE_PTR( S2_Hushbutton_PCI ), 566 );
    Globals->S2_Hushbutton_PCI.__NWAITINGFORACK = 0; 
    
    S2_Hushbutton_PCI_Exit__MAIN:/* Begin Free local function variables */
    /* End Free local function variables */
    
    RESTORE_GLOBAL_POINTERS ;
    return 0 ;
    }

