//
//  WPError.h
//  WePay
//
//  Created by Chaitanya Bagaria on 12/22/14.
//  Copyright (c) 2014 WePay. All rights reserved.
//

#import <Foundation/Foundation.h>
/** \file WPError.h
 * \brief WPError.h serves as documentation for all errors surfaced by the WePay iOS SDK.
 * 
 * When errors occur, the WePay iOS SDK returns NSError instances to delegate methods.
 * Each error instance has the following components:
 * - [error code] gives the integer code corresponding with the error
 * - [error domain] gives the domain that the error belongs to
 * - [error userInfo] gives a dictionary with some more useful info, which can be accessed with the keys kWPErrorCategoryKey and NSLocalizedDescriptionKey
 *
 * The WePay iOS SDK can return errors in various error domains:
 * - WePay server API errors are in the \ref kWPErrorAPIDomain
 * - Errors generated by the SDK itself are in the \ref kWPErrorSDKDomain
 * - System errors generated by iOS are passed through as-is, for example in the NSURLErrorDomain
 *
 * See the \ref WPErrorCode section for more details about error codes.
 */

#pragma mark - WPError constants.

/**
 *  The NSError domain of all errors surfaced by the WePay iOS SDK that were returned by the WePay API.
 *  For a full list of error codes in the \ref kWPErrorAPIDomain, visit https://www.wepay.com/developer/reference/errors
 */
FOUNDATION_EXPORT NSString * const kWPErrorAPIDomain;

/**
 *  The NSError domain of all errors returned by the WePay iOS SDK itself.
 *  For a full list of error codes in the \ref kWPErrorSDKDomain, look at \ref WPErrorCode.
 */
FOUNDATION_EXPORT NSString * const kWPErrorSDKDomain;

/**
 *  The key used in the NSError's userInfo dictionary to return the error category.
 */
FOUNDATION_EXPORT NSString * const kWPErrorCategoryKey;

/**
 *  The value used in the NSError's userInfo dictionary to return the "none" error category.
 */
FOUNDATION_EXPORT NSString * const kWPErrorCategoryNone;

/**
 *  The value used in the NSError's userInfo dictionary to return the "card reader" error category.
 */
FOUNDATION_EXPORT NSString * const kWPErrorCategoryCardReader;

/**
 *  The value used in the NSError's userInfo dictionary to return the "sdk" error category.
 */
FOUNDATION_EXPORT NSString * const kWPErrorCategoryCardSDK;

#pragma mark - Error Codes.

/**
 *  Error codes for NSErrors surfaced by the WePay iOS SDK in the \ref kWPErrorSDKDomain.
 *  For a full list of error codes in the \ref kWPErrorAPIDomain, visit https://www.wepay.com/developer/reference/errors
 */
typedef enum WPErrorCode {
    /**
     *  -10000 Unknown error.
     */
    WPErrorUnknown              = -10000,
    
    // -10001 to -10014 are reserved for legacy error codes
    
    /**
     *  -10015 No data returned by the API call.
     */
    WPErrorNoDataReturned       = -10015,
    
    /**
     *  -10016 General error reported by the card reader - usually due to a bad swipe.
     */
    WPErrorCardReaderGeneralError   = -10016,
    
    /**
     *  -10017 Error while initializing the card reader.
     */
    WPErrorCardReaderInitialization = -10017,
    
    /**
     *  -10018 Timeout occurred while waiting for card.
     */
    WPErrorCardReaderTimeout        = -10018,
    
    /**
     *  -10019 Special error reported by card reader - very rare.
     */
    WPErrorCardReaderStatusError    = -10019,
    
    /**
     *  -10020 Invalid signature image.
     */
    WPErrorInvalidSignatureImage    = -10020,

    /**
     *  -10021 Name not found.
     */
    WPErrorNameNotFound         = -10021,

    /**
     *  -10022 Invalid card data.
     */
    WPErrorInvalidCardData = -10022,

    /**
     *  -10023 Card not supported.
     */
    WPErrorCardNotSupported = -10023,

    /**
     *  -10024 EMV transaction error.
     */
    WPErrorEMVTransactionError = -10024,

    /**
     *  -10025 Invalid application ID.
     */
    WPErrorInvalidApplicationId = -10025,

    /**
     *  -10026 Declined by card.
     */
    WPErrorDeclinedByCard = -10026,

    /**
     *  -10027 Card blocked.
     */
    WPErrorCardBlocked = -10027,

    /**
     *  -10028 Declined by issuer.
     */
    WPErrorDeclinedByIssuer = -10028,

    /**
     *  -10029 Issuer unreachable.
     */
    WPErrorIssuerUnreachable = -10029,
    
    /**
     *  -10030 Invalid auth info.
     */
    WPErrorInvalidAuthInfo = -10030,
    
    /**
     *  -10031 Auth info not provided.
     */
    WPErrorAuthInfoNotProvided = -10031,
    
    /**
     *  -10032 Payment method cannot be tokenized.
     */
    WPErrorPaymentMethodCannotBeTokenized = -10032,

    /**
     *  -10033 Failed to get battery level.
     */
    WPErrorFailedToGetBatteryLevel = -10033,
    
    /**
     *  -10034 Card reader not connected.
     */
    WPErrorCardReaderNotConnected = -10034,
    
    /**
     *  -10035 Card reader model not supported.
     */
    WPErrorCardReaderModelNotSupported = -10035,
    
    /**
     *  -10036 Invalid transaction amount.
     */
    WPErrorInvalidTransactionAmount = -10036,
    
    /**
     *  -10037 Invalid transaction currency code.
     */
    WPErrorInvalidTransactionCurrencyCode = -10037,
    
    /**
     *  -10038 Invalid transaction account id.
     */
    WPErrorInvalidTransactionAccountID = -10038,
    
    /**
     *  -10039 Invalid card reader selection.
     */
    WPErrorInvalidCardReaderSelection = -10039,

    /**
     *  -10040 Card reader battery too low.
     */
	WPErrorCardReaderBatteryTooLow = -10040,

    /**
     *  -10041 Unable to connect to card reader.
     */
    WPErrorCardReaderUnableToConnect = -10041

} WPErrorCode;

#pragma mark - User facing messages.

/**
 *  The localizable user facing message for WPErrorUnknown, that can be retrieved by calling [error localizedDescription].
 */
#define WPUnexpectedErrorMessage NSLocalizedStringFromTable(@"There was an unexpected error.", @"WePay", @"There was an unexpected error.");

/**
 *  The localizable user facing message for WPErrorNoDataReturned, that can be retrieved by calling [error localizedDescription].
 */
#define WPNoDataReturnedErrorMessage NSLocalizedStringFromTable(@"There was no data returned.", @"WePay",  @"There was no data returned.");

/**
 *  The localizable user facing message for WPErrorCardReaderGeneralError, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardReaderGeneralErrorMessage NSLocalizedStringFromTable(@"Swipe failed due to: (a) uneven swipe speed, (b) fast swipe, (c) slow swipe, or (d) damaged card.", @"WePay",  @"Swipe failed due to: (a) uneven swipe speed, (b) fast swipe, (c) slow swipe, or (d) damaged card.");

/**
 *  The localizable user facing message for WPErrorCardReaderInitialization, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardReaderInitializationErrorMessage NSLocalizedStringFromTable(@"Failed to initialize card reader.", @"WePay",  @"Failed to initialize card reader.");

/**
 *  The localizable user facing message for WPErrorCardReaderTimeout, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardReaderTimeoutErrorMessage NSLocalizedStringFromTable(@"Card reader timed out.", @"WePay",  @"Card reader timed out.");

/**
 *  The localizable user facing message for WPErrorInavlidSignatureImage, that can be retrieved by calling [error localizedDescription].
 */
#define WPSignatureInvalidImageErrorMessage NSLocalizedStringFromTable(@"Inavlid signature image provided.", @"WePay",  @"Inavlid signature image provided.");

/**
 *  The localizable user facing message for WPErrorNameNotFound, that can be retrieved by calling [error localizedDescription].
 */
#define WPNameNotFoundErrorMessage NSLocalizedStringFromTable(@"Name not found.", @"WePay",  @"Name not found.");

/**
 *  The localizable user facing message for WPErrorInvalidCardData, that can be retrieved by calling [error localizedDescription].
 */
#define WPInvalidCardDataErrorMessage NSLocalizedStringFromTable(@"Invalid card data.", @"WePay",  @"Invalid card data.");

/**
 *  The localizable user facing message for WPErrorCardNotSupported, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardNotSupportedErrorMessage NSLocalizedStringFromTable(@"This card is not supported.", @"WePay",  @"This card is not supported.");

/**
 *  The localizable user facing message for WPErrorInvalidApplicationId, that can be retrieved by calling [error localizedDescription].
 */
#define WPInvalidApplicationIdErrorMessage NSLocalizedStringFromTable(@"Invalid application ID selected.", @"WePay",  @"Invalid application ID selected.");

/**
 *  The localizable user facing message for WPErrorDeclinedByCard, that can be retrieved by calling [error localizedDescription].
 */
#define WPDeclinedByCardErrorMessage NSLocalizedStringFromTable(@"The transaction was declined by the card.", @"WePay",  @"The transaction was declined by the card.");

/**
 *  The localizable user facing message for WPErrorCardBlocked, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardBlockedErrorMessage NSLocalizedStringFromTable(@"This card has been blocked.", @"WePay",  @"This card has been blocked.");

/**
 *  The localizable user facing message for WPErrorDeclinedByIssuer, that can be retrieved by calling [error localizedDescription].
 */
#define WPDeclinedByIssuerErrorMessage NSLocalizedStringFromTable(@"The transaction was declined by the issuer bank.", @"WePay",  @"The transaction was declined by the issuer bank.");

/**
 *  The localizable user facing message for WPErrorIssuerUnreachable, that can be retrieved by calling [error localizedDescription].
 */
#define WPIssuerUnreachableErrorMessage NSLocalizedStringFromTable(@"The issuing bank could not be reached.", @"WePay",  @"The issuing bank could not be reached.");

/**
 *  The localizable user facing message for WPErrorInvalidAuthInfo, that can be retrieved by calling [error localizedDescription].
 */
#define WPInvalidAuthInfoErrorMessage NSLocalizedStringFromTable(@"The provided auth info is invalid.", @"WePay",  @"The provided auth info is invalid.");

/**
 *  The localizable user facing message for WPErrorAuthInfoNotProvided, that can be retrieved by calling [error localizedDescription].
 */
#define WPAuthInfoNotProvidedErrorMessage NSLocalizedStringFromTable(@"Auth info was not provided.", @"WePay",  @"Auth info was not provided.");

/**
 *  The localizable user facing message for WPErrorPaymentMethodCannotBeTokenized, that can be retrieved by calling [error localizedDescription].
 */
#define WPPaymentMethodCannotBeTokenizedErrorMessage NSLocalizedStringFromTable(@"This payment method cannot be tokenized.", @"WePay",  @"This payment method cannot be tokenized.");

/**
 *  The localizable user facing message for WPErrorFailedToGetBatteryLevel, that can be retrieved by calling [error localizedDescription].
 */
#define WPFailedToGetBatteryLevelErrorMessage NSLocalizedStringFromTable(@"Battery level could not be determined.", @"WePay",  @"Battery level could not be determined.");

/**
 *  The localizable user facing message for WPErrorCardReaderNotConnected, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardReaderNotConnectedErrorMessage NSLocalizedStringFromTable(@"Card reader is not connected.", @"WePay",  @"Card reader is not connected.");

/**
 *  The localizable user facing message for WPErrorCardReaderModelNotSupported, that can be retrieved by calling [error localizedDescription].
 */
#define WPCardReaderModelNotSupportedErrorMessage NSLocalizedStringFromTable(@"This card reader model is not supported.", @"WePay",  @"This card reader model is not supported.");

/**
 * The localizable user facing message for WPErrorInvalidTransactionAmount, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorInvalidTransactionAmountErrorMessage NSLocalizedStringFromTable(@"The provided transaction amount is invalid.", @"WePay", @"The provided transaction amount is invalid.");

/**
 *  The localizable user facing message for WPErrorInvalidTransactionCurrencyCode, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorInvalidTransactionCurrencyCodeErrorMessage NSLocalizedStringFromTable(@"The provided currency code is invalid.", @"WePay",  @"The provided currency code is invalid.");

/**
 *  The localizable user facing message for WPErrorInvalidTransactionAccountID, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorInvalidTransactionAccountIDErrorMessage NSLocalizedStringFromTable(@"The provided account ID is invalid.", @"WePay",  @"The provided account ID is invalid.");

/**
 *  The localizable user facing message for WPErrorInvalidCardReaderSelection, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorInvalidCardReaderSelectionErrorMessage NSLocalizedStringFromTable(@"Card reader selection is invalid.", @"WePay",  @"Card reader selection is invalid.");

/**
 *  The localizable user facing message for WPErrorCardReaderBatteryTooLow, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorCardReaderBatteryTooLowErrorMessage NSLocalizedStringFromTable(@"The card reader battery does not have enough charge. Please charge before using.", @"WePay",  @"The card reader battery does not have enough charge. Please charge before using.");

/**
 *  The localizable user facing message for WPErrorCardReaderUnsupportedOrBatteryTooLow, that can be retrieved by calling [error localizedDescription].
 */
#define WPErrorCardReaderUnableToConnectErrorMessage NSLocalizedStringFromTable(@"Please make sure you’re using a supported card reader and that it is fully charged.", @"WePay",  @"Please make sure you’re using a supported card reader and that it is fully charged.");