#ifndef __SECURITY_SERVICES_ERROR_H__
#define __SECURITY_SERVICES_ERROR_H__

/******************************************************************************
"Copyright (c) 2015-2015, Intel Corporation
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"
******************************************************************************/

/** @file 
	@brief Main API error list.
*/

#include "xss_types.h"

/** creates and fills error data with specified error code
* @param [in] error_code - error code to set.
* @see  ss_error_code_t
* @return sservice_result_t, filled with required data.
*/

#define SET_ERROR_CODE( result, errorCode ) \
{\
	result.is_success=SSERVICE_ERROR ;\
	result.reserved = 0;\
	result.error_or_warn_code = errorCode ;\
}

static inline sservice_result_t  CREATE_ERROR( int error_code ) 
{
	sservice_result_t r;
	SET_ERROR_CODE( r, error_code )
	return r;							
} 


/** creates and fills return value with success information
* @param [in] info_code - info code to set.
* @return sservice_result_t, filled with required data.
*/
static inline sservice_result_t  CREATE_SUCCESS( int info_code ) 
{
	sservice_result_t r;			
	r.is_success = SSERVICE_SUCCESS ;	
	r.reserved = 0;					
	r.error_or_warn_code = info_code;	
	return r;							
} 

enum ss_success_code_t
{
	SSERVICE_SUCCESSCODE_NOINFO =0,
};

/** 
* @typedef ss_error_code_t
* Error codes
*/
typedef enum 
{
	SSERVICE_ERRORCODE_FILESYSTEMERROR = 1,							/**< failed when accessing to medium */
	SSERVICE_ERRORCODE_INSUFFICIENTMEMORY = 2,						/**< cannot allocate required memory. Data too large or device out of memory? */
	SSERVICE_ERRORCODE_INVALIDIDENTIFIER = 3,						/**< invalid storage id ( wrong file name? ) in input parameters */
	SSERVICE_ERRORCODE_INVALIDNUMBEROFOWNERS = 4,					/**< invalid( not 1 ) number of owners in input parameters */
	SSERVICE_ERRORCODE_INVALIDPERSONA = 5,							/**< Wrong persona in input parameters */
	SSERVICE_ERRORCODE_WRONGPERSON = 5,								/**< current active persona is not one of owners of the data. Cannot access */
	SSERVICE_ERRORCODE_INVALIDPOLICY = 6,							/**< invalid policy in input parameters (as min, one of the fields has illegal value) */
	SSERVICE_ERRORCODE_ADDITIONALCREDENTIALSPOLICYVOILATION = 7,	/**< additional credentials policy voilation */
	SSERVICE_ERRORCODE_INVALIDINPUTSIZE = 7,						/**< invalid size in input parameters */
	SSERVICE_ERRORCODE_INTEGRITYVIOLATIONERROR = 8,					/**< signature is not suit to data content. Probably File is broken */
	SSERVICE_ERRORCODE_INVALIDHANDLE = 9,							/**< Handle is not exists ore invalid */
	SSERVICE_ERRORCODE_INVALIDTYPE = 10,							/**< invalid storage type ( not local storage? ) in input parameters */
	SSERVICE_ERRORCODE_STORAGE_IDENTIFIER_ALREADY_IN_USE = 11,	
	SSERVICE_ERRORCODE_POLICYVIOLATIONDETECTED = 13,				/**< Policy violation detected  */
	SSERVICE_ERRORCODE_INVALID_WEB_DOMAINS_LIST_SIZE = 14,			
	SSERVICE_ERRORCODE_SERVER_NOT_ACCESSIBLE = 16,
	SSERVICE_ERRORCODE_CONNECTION_TIMEOUT = 17,
	SSERVICE_ERRORCODE_CONNECTION_GENERIC=18,
	SSERVICE_ERRORCODE_INVALID_DESCRIPTOR_STRUCTURE = 19,
	SSERVICE_ERRORCODE_INVALID_DESCRIPTOR_PATH = 20,
	SSERVICE_ERRORCODE_INVALID_TIMEOUT = 22,
	SSERVICE_ERRORCODE_DESCRIPTOR_NOT_SUPPORTED_FOR_REQUEST_FORMAT = 23,
	SSERVICE_ERRORCODE_INVALID_REQUEST_FORMAT = 24,
	SSERVICE_ERRORCODE_INVALID_REQUEST_BODY_STRUCTURE= 26,
	SSERVICE_ERRORCODE_INVALID_RESPONSE_BODY_STRUCTURE= 27,
	SSERVICE_ERRORCODE_INVALID_URL = 29,
	SSERVICE_ERRORCODE_INVALID_HTTP_METHOD = 30,
	SSERVICE_ERRORCODE_BAD_CERTIFICATE_FORMAT = 32,
	SSERVICE_ERRORCODE_SERVER_AUTENTICATION_ERROR = 33,
	SSERVICE_ERRORCODE_INVALID_ARGUMENT_SIZE= 34,
	SSERVICE_ERRORCODE_INCORRECT_STATE = 35,
	SSERVICE_ERRORCODE_ACTION_ABORTED = 36,
	SSERVICE_ERRORCODE_INTERNAL_ERROR = 1000,						/**< Some error inside the runtime. */
	SSERVICE_ERRORCODE_BRIDGE_INTERNAL_ERROR = 1001,				/**< Some error inside the bridge. */
	SSERVICE_ERRORCODE_CORDOVA_ERROR = 1002,						/**< Some error inside the cordova. Wrong parameters are passed */
	SSERVICE_ERRORCODE_NOTIMPLEMENTED = 1003,						/**< Not implemented code is called */
	//SSERVICE_ERRORCODE_COMMUNICATIONERROR = 1004,					/**< Cannot access remote server. */
	SSERVICE_ERRORCODE_INSUFFICIENTTRUSTLEVEL = 1005,				/**< current active persona has not enough trust level to access the data */
	SSERVICE_ERRORCODE_INVALIDPOINTER = 1006,						/**< invalid pointer in input parameters */
	SSERVICE_ERRORCODE_INVALIDBUFFERSIZE = 1007,					/**< invalid( not enough ) buffer size in input parameters */
	SSERVICE_ERRORCODE_MEMCPY = 1008,								/**< secure_memcpy failed*/
	SSERVICE_ERRORCODE_CRYPTO = 1009,								/**< Error in crypto operation*/
}ss_error_code_t; 



#define SSERVICE_SUCCESS_NOINFO CREATE_SUCCESS( SSERVICE_SUCCESSCODE_NOINFO )
#define SSERVICE_ERROR_INVALIDPOINTER								  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDPOINTER			)
#define SSERVICE_ERROR_INVALIDINPUTSIZE	   						      CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDINPUTSIZE			)
#define SSERVICE_ERROR_INVALIDBUFFERSIZE							  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDBUFFERSIZE		)
#define SSERVICE_ERROR_INVALIDHANDLE								  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDHANDLE			)
#define SSERVICE_ERROR_INVALIDPERSONA								  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDPERSONA			)
#define SSERVICE_ERROR_INVALIDNUMBEROFOWNERS						  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDNUMBEROFOWNERS	)
#define SSERVICE_ERROR_POLICYVIOLATIONDETECTED						  CREATE_ERROR( SSERVICE_ERRORCODE_POLICYVIOLATIONDETECTED	)
#define SSERVICE_ERROR_INVALIDWEBDOMAINSLISTSIZE					  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_WEB_DOMAINS_LIST_SIZE		)
#define SSERVICE_ERROR_INVALIDPOLICY								  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDPOLICY			)
#define SSERVICE_ERROR_ADDITIONALCREDENTIALSPOLICYVOILATION			  CREATE_ERROR( SSERVICE_ERRORCODE_ADDITIONALCREDENTIALSPOLICYVOILATION)
#define SSERVICE_ERROR_INVALIDIDENTIFIER							  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDIDENTIFIER		)
#define SSERVICE_ERROR_INVALIDTYPE									  CREATE_ERROR( SSERVICE_ERRORCODE_INVALIDTYPE				)
#define SSERVICE_ERROR_STORAGE_IDENTIFIER_ALREADY_IN_USE			  CREATE_ERROR( SSERVICE_ERRORCODE_STORAGE_IDENTIFIER_ALREADY_IN_USE)
#define SSERVICE_ERROR_INSUFFICIENTMEMORY							  CREATE_ERROR( SSERVICE_ERRORCODE_INSUFFICIENTMEMORY		)
#define SSERVICE_ERROR_FILESYSTEMERROR								  CREATE_ERROR( SSERVICE_ERRORCODE_FILESYSTEMERROR			)
#define SSERVICE_ERROR_INTEGRITYVIOLATIONERROR						  CREATE_ERROR( SSERVICE_ERRORCODE_INTEGRITYVIOLATIONERROR	)
#define SSERVICE_ERROR_INSUFFICIENTTRUSTLEVEL						  CREATE_ERROR( SSERVICE_ERRORCODE_INSUFFICIENTTRUSTLEVEL	)
#define SSERVICE_ERROR_WRONGPERSONA									  CREATE_ERROR( SSERVICE_ERRORCODE_WRONGPERSON				)
//#define SSERVICE_ERROR_COMMUNICATIONERROR							  CREATE_ERROR( SSERVICE_ERRORCODE_COMMUNICATIONERROR		)
#define SSERVICE_ERROR_INTERNAL_ERROR								  CREATE_ERROR( SSERVICE_ERRORCODE_INTERNAL_ERROR           )
#define SSERVICE_ERROR_BRIDGE_INTERNAL_ERROR 						  CREATE_ERROR( SSERVICE_ERRORCODE_BRIDGE_INTERNAL_ERROR    )
#define SSERVICE_ERROR_NOTIMPLEMENTED								  CREATE_ERROR( SSERVICE_ERRORCODE_NOTIMPLEMENTED			)
#define SSERVICE_ERROR_CORDOVA_ERROR								  CREATE_ERROR( SSERVICE_ERRORCODE_CORDOVA_ERROR			)
#define SSERVICE_ERROR_MEMCPY										  CREATE_ERROR( SSERVICE_ERRORCODE_MEMCPY					)
#define SSERVICE_ERROR_CRYPTO										  CREATE_ERROR( SSERVICE_ERRORCODE_CRYPTO					)
#define SSERVICE_ERROR_SERVER_NOT_ACCESSIBLE						  CREATE_ERROR( SSERVICE_ERRORCODE_SERVER_NOT_ACCESSIBLE)
#define SSERVICE_ERROR_CONNECTION_TIMEOUT							  CREATE_ERROR( SSERVICE_ERRORCODE_CONNECTION_TIMEOUT		)
#define SSERVICE_ERROR_CONNECTION_GENERIC							  CREATE_ERROR( SSERVICE_ERRORCODE_CONNECTION_GENERIC		)
#define SSERVICE_ERROR_INVALID_DESCRIPTOR_STRUCTURE					  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_DESCRIPTOR_STRUCTURE)
#define SSERVICE_ERROR_INVALID_DESCRIPTOR_PATH						  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_DESCRIPTOR_PATH)
#define SSERVICE_ERROR_INVALID_TIMEOUT								  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_TIMEOUT)
#define SSERVICE_ERROR_DESCRIPTOR_NOT_SUPPORTED_FOR_REQUEST_FORMAT	  CREATE_ERROR( SSERVICE_ERRORCODE_DESCRIPTOR_NOT_SUPPORTED_FOR_REQUEST_FORMAT)
#define SSERVICE_ERROR_INVALID_REQUEST_FORMAT						  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_REQUEST_FORMAT)
#define SSERVICE_ERROR_INVALID_REQUEST_BODY_STRUCTURE				  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_REQUEST_BODY_STRUCTURE)
#define SSERVICE_ERROR_INVALID_RESPONSE_BODY_STRUCTURE				  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_RESPONSE_BODY_STRUCTURE)
#define SSERVICE_ERROR_INVALID_URL									  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_URL)
#define SSERVICE_ERROR_INVALID_HTTP_METHOD							  CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_HTTP_METHOD)
#define SSERVICE_ERROR_BAD_CERTIFICATE_FORMAT						  CREATE_ERROR( SSERVICE_ERRORCODE_BAD_CERTIFICATE_FORMAT)
#define SSERVICE_ERROR_SERVER_AUTENTICATION_ERROR					  CREATE_ERROR( SSERVICE_ERRORCODE_SERVER_AUTENTICATION_ERROR)
#define SSERVICE_ERROR_INVALID_ARGUMENT_SIZE				          CREATE_ERROR( SSERVICE_ERRORCODE_INVALID_ARGUMENT_SIZE)
#define SSERVICE_ERROR_INCORRECT_STATE								  CREATE_ERROR( SSERVICE_ERRORCODE_INCORRECT_STATE)
#define	SSERVICE_ERROR_ACTION_ABORTED								  CREATE_ERROR( SSERVICE_ERRORCODE_ACTION_ABORTED)

/** checks if result is success
* @param [in] res - result information.
* @see  sservice_result_t
* @return bool, indicating if success in result.
*/
#define IS_SUCCESS(res)  (res.is_success == SSERVICE_SUCCESS )
/** checks if result is failure
* @param [in] res - result information.
* @see  sservice_result_t
* @return bool, indicating if failure in result.
*/
#define IS_FAILED(res) (res.is_success == SSERVICE_ERROR )



#endif
