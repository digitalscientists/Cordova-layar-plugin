/**
 * @file LayarPlayer.hpp
 * @brief Main include file of the LayarPlayer SDK
 *
 * Include this file to include all public header files of the Layar SDK
 * By implementing the Layar SDK in your application, you agree to the Terms and Conditions described in the Layar_Software_Development_Kit_License_Agreement.pdf
 * file which can be found in the LayarSDK documentation folder
 *
 * @authors Lawrence Lee, Anatoliy Samara, Dirk Groten and Bastian Lengert, Layar B.V.
 * @date 21 March 2013
 */

#import "LayarPlayerDelegate.h"
#import "LPARVisionViewController.hpp"

/**
 * @mainpage Layar SDK Documentation v7.2.4
 *
 * @section introduction Introduction
 *
 * The Layar SDK is an Xcode framework that implements the core functionality of Layar. Using the Layar SDK it is
 * possible to present the Augmented Reality view to the user. The user will be able to scan objects that may be augmented using Layar Vision or the Layar Creator. The Layar SDK will only return content linked to the user account who registered the application in which the Layar SDK is embedded. The Layar SDK will start all necessary
 * services such as the camera and device motion control.
 *
 * Important note: The Layar SDK v7.2.4 supports vision layers as well as QR Codes but it will not support rendering of geo layers!
 *
 * @section minimumrequirements Minimum requirements
 *
 * The Layar SDK requires a minimum installed iOS version of 5.1, and that the device capabilities include OpenGL ES 2 support,
 * location support, a camera, magnetometer and an accelerometer. The Layar SDK is also built for ARM7+ architecture.
 * The application in which the LayarSDK.framework is used should reflect this by specifying the folowing values
 * in the applications .plist for the key UIRequiredDeviceCapabilities:
 *
 * @li opengles-2
 * @li video-camera
 * @li accelerometer
 * @li magnetometer
 * @li location-services
 * @li armv7
 *
 * @section projectconfiguration Project configuration
 *
 * Any project using the Layar SDK must have the "Minimum OS Version" set to 5.1. It must also specify "Architectures" of armv7 and armv7s.
 *
 * To use SDK in an application project do the following:
 * @li add LayarSDK.framework to the “Link Binary With Libraries” build phase
 * @li add dependent frameworks there also (list below)
 * @li add -ObjC flag to “Other Linker Flags” in build settings (otherwise it will crash for class categories)
 * @li add LayarSDK.framework/Resources/LayarSDKResources.bundle to your app resources, e.g. in the "Supporting Files" group (a group that XCode 4.5 automatically creates when you create a new project).

 * @subsection frameworks List of dependent frameworks
 *
 * @li libc++.dylib
 * @li libiconv.dylib
 * @li libxml2.dylib
 * @li libz.dylib
 * @li AddressBook.framework
 * @li AddressBookUI.framework
 * @li AudioToolbox.framework
 * @li AVFoundation.framework
 * @li CFNetwork.framework
 * @li CoreAudio.framework
 * @li CoreData.framework
 * @li CoreLocation.framework
 * @li CoreMedia.framework
 * @li CoreMotion.framework
 * @li CoreVideo.framework
 * @li CoreTelephony.framework
 * @li CoreGraphics.framework
 * @li Foundation.framework
 * @li MediaPlayer.framework
 * @li MessageUI.framework
 * @li OpenAL.framework
 * @li OpenGLES.framework
 * @li Security.framework
 * @li Social.framework
 * @li SystemConfiguration.framework
 * @li Twitter.framework
 * @li QuartzCore.framework
 * @li UIKit.framework
 *
 * The Social.framework should be marked as (optional) in Xcode to support iOS5.
 *
 
 * @subsection externallibs External Libraries
 *
 * The Layar SDK uses some external open source libraries that you might want to use in your own project. In order to avoid symbol conflicts, we're distributing the libraries as separate static libraries together with the Layar SDK. You need to link your project against the binary static libraries (see Build Configuration section below).
 *
 * If you use the libraries in your application, you'll need to include the path to the header files in the "Header search paths" of your project's build configuration. 
 * You may want to use newer versions of these libraries, in such cases make sure you link against those compiled static libraries. As long as backward compatibility is maintained, it should work, but Layar makes no guarantees if a different version is used. The two libraries are:
 *
 * @li json-framework by Stig Brautaset: https://github.com/stig/json-framework (v3.0.4 rev 87a86811ba)
 * @li MPOAuthConnection by Karl Adam: https://github.com/thekarladam/MPOAuth (rev 1609e85)
 *
 * All other open-source libraries we use should be obfuscated or consist of header files only, so they shouldn't lead to conflicts. If nevertheless you hit a conflict just let us know and we'll send you the relevant header files.
 *
 * @subsubsection armv7 Armv7 Build Configuration
 *
 * When building the application the following steps must be taken to ensure that the project links against the "LayarSDK.framework" framework. The instructions below were made using XCode 4.5.2 (4G2008a).
 *
 * The project settings should have the following changes made:
 *
 * @li The "Architectures" option set to "Standard (armv7, armv7s)"
 * @li The "Valid Architectures" option should contain "armv7" and "armv7s"
 $ @li The "Base SDK" option should be set to "Latest iOS"
 * @li The "iOS Deployment Target" option should be set to "iOS 5.1"
 * @li If you wish to use the "#import <...>" import directive, you must ensure that the "Always search user paths" option is enabled
 * @li In the "Build Phases" of your target, the "Link Binary with Libraries" option must also contatin libsbjson-ios.a and libMPOAuthMobile.a from external libraries supplied with LayarSDK. Note: If your project already includes these libraries, you can skip this step.
 * @li The "Other linker flags" option must contain the flags @c -ObjC.
 * @li The "C Language Dialect" option must be set to GNU99.
 * @li The "C++ Language Dialict" option must be set to GNU++11.
 * @li The "C++ Standard Library" option must be set to libC++.
 *
 * @section usage Usage
 *
 * In order to use the Layar SDK in an application, you need to import the LayarPlayer.hpp in the class file that will launch the AR view controller. Note that since it's an Objective-C++
 * header file, you'll need to change any file that imports it into an Objective-C++ file as well (e.g. MyViewController.mm would import LayarPlayer.hpp, so 
 * MyViewController.hpp is the corresponding header file). In practice, all view controllers in the hierarchy above MyViewController, the AppDelegate,
 * and main will need to be renamed as (Objective-)C++ files.
 *
 * When you wish to launch the LayarSDK Augmented Reality view, initialize an instance of the @c LPARViewController. It is imperative that you present the
 * LPARViewController modally in order for it to function correctly.
 * The LayerSDK also supports backgrounding, and will pause all OpenGL rendering as well as relenquishing all device hardware usage.
 *
 * @subsection example Example
 *
 * The following code snippet can be used to present an Augmented Reality View and load a layer:
 *
 * @code
 * #import <LayarSDK/LayarPlayer.hpp>
 * ...
 * NSString *consumerKey = ...;
 * NSString *consumerSecret = ...;
 *
 * LPARVisionViewController *augmentedRealityViewController = [[LPARVisionViewController alloc] init];
 * augmentedRealityViewController.oauthConsumerKey = consumerKey;
 * augmentedRealityViewController.oauthConsumerSecret = consumerSecret;
 * augmentedRealityViewController.delegate = self;
 * [self presentViewController:augmentedRealityViewController animated:YES completion:nil];
 * @endcode
 *
 * @subsubsection oauth OAuth signing
 *
 * All requests made by the LayarSDK need have a valid OAuth key and secret sent with them in order to successfully pass authentication checks by the Layar server.
 * This information is specific to each app, and must be configured by Layar staff. Please contact devsupport@layar.com to ensure your signing keys are valid.
 *
 * @subsubsection delegatemethods Delegate methods
 *
 * By implementing the @c LayarPlayerDelegate protocol a program can receive events from the LayarPlayer. Currently we offer four callbacks: 
 *
 * @li @c layarPlayerWillClose The user tapped the "Close" button in one of the views and the LPARVisionViewController will dismiss
 * @li @c layarPlayerDidClose The user tapped the "Close" button and the LPARVisionViewController did dismiss
 * @li @c layarPlayerDidLaunchLayer:(NSString*)layerName withTitle:(NSString*)layerTitle
 * @li @c layarPlayerStartedTrackingReferenceImage:(NSString*)referenceImageName withLayer:(NSString*)layerName withTitle:(NSString*)layerTitle
 *
 * Example implementation:
 *
 * @code
 * ...
 *
 * #pragma mark - LayarPlayerDelegate methods
 *
 * - (void)layarPlayerWillClose {
 *		// add own code to execute before LPARVisionViewController is dismissed
 * }
 *
 * - (void)layarPlayerDidClose {
 *		// add own code to execute after LPARVisionViewController was dismissed
 * }
 *
 * - (void)layarPlayerDidLaunchLayer:(NSString*)layerName withTitle:(NSString*)layerTitle {
 *		// Use the layerName (campaign name) and layerTitle (campaign title)
 * }
 *
 * - (void)layarPlayerStartedTrackingReferenceImage:(NSString*)referenceImageName withLayer:(NSString*)layerName withTitle:(NSString*)layerTitle {
 *		// Use the referenceImageName, layerName (campaign name) and LayerTitle (campaign title)
 * }
 *
 * ...
 * @endcode
 *
 * @section launchingfromopenglapp Launching the LayarSDK from OpenGL applications
 *
 * Extra attention must be paid to resource management when launching the LayarSDK from an application that makes use of OpenGL to render content. The LayarSDK is a resource
 * intensive application, and to avoid spawning memory warnings on the device it is running on, any application launching the LayarPlayer should free up as many resources as possible.
 * For OpenGL applications this means that all texture resources should be deleted, and if possible any framebuffers that are in use. Any OpenGL timers or display links should be paused
 * as well. By implementing the delegate methods and assigning a suitable delegate class, the application can rebind its resources when the LayarPlayer closes. Care should be taken to
 * set the application's own OpenGL context when doing so. More information on OpenGL context switching can be found here:
 * http://developer.apple.com/library/ios/#documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/WorkingwithOpenGLESContexts/WorkingwithOpenGLESContexts.html
 *
 
 * @section branding Overriding strings and graphics
 
 * Everything that you can override is inside the LayarSDK.framework/Resources/LayarSDKResources.bundle. It includes localizable strings and graphical assets that can be replaced.
 
 * There are basically two ways to do this.
 * @subsection easy The easy way
 
 * @li Pro: easy
 * @li Con: default resources will still be present in your app bundle (inside LayarSDKResources.bundle), though not used.
 
 * For text strings the SDK uses iOS localization mechanics. Thus, all strings are contained in LayarSDKResources.bundle/en.lproj/Localizable.strings file. The SDK is also built in a way to allow overriding/localizing any string. It first looks for strings in main bundle localization tables, then if not found falls back to LayarSDKResources.bundle localizations. So to replace a string do this:
 * @li Add localization .strings file(s) to your application
 * @li Look into LayarSDKResources.bundle/en.lproj/Localizable.strings file to find a string to replace
 * @li Add a string with the same key into your app’s .strings file(s).
 
 * For images the SDK tries to load files from main bundle first, and if not found falls back to a file in LayarSDKResources.bundle. So, to replace an image:
 * @li Look into LayarSDKResources.bundle and find the asset you want to replace
 * @li Create the files with the same names (usually there are several versions of the same file for different screen resolutions, e.g. …@2x for retina etc.)
 * @li Add the files to your app resources (main bundle).
 
 
 * @subsection hard The hard way
 
 * @li Pro: you have full control of what is included in your app
 * @li Con: you need to keep track of what was changed when we update the sdk
 
 * Copy LayarSDK.framework/Resources/LayarSDKResources.bundle, modify it and include a modified version into your project.
 
 * @section Localization
 * Since version 7.2.4 the LayarSDK supports localization. You are provided with localizations for English, Dutch, German, French, Spanish and Japanese. In case you would like to provide text that is specific to your application you can change the strings for all languages or add new languages.
 * To do this you provide a "Localizable.strings" file in your project. In this file you can overwrite the predefined text on a per string basis.
 * If you want to for example change the "Point to scan" introduction title you provide a new string in your english localization file like this:
 
 * @code
 * // Point and scan
 * "Point and scan" = "Now point!";
 * @endcode
 
 * If you plan to add a new language you need to localize the "Localizable.strings" file and you can add strings for any language. You should make sure that you provide a translation for all strings. Also you should try to keep a similar string length to not have the string cut off.
 
 * Availiable strings:

 * @code
 * // Close
 * // Close view
 * "Close" = "Close";
 *
 * // Scan
 * "Scan" = "Scan"
 *
 * // Cancel
 * "Cancel" = "Cancel";
 *
 * // Analyzing…
 * "Analyzing…" = "Analyzing…";
 *
 * // Nothing found
 * "Nothing found" = "Nothing found";
 *
 * // Tap to continue
 * "Tap to continue" = "Tap to continue";
 *
 * // Make sure this item has content or try holding your device steady as you scan.
 * "Make sure this item has content or try holding your device steady as you scan." = "Make sure this item has content or try holding your device steady as you scan.";
 *
 * // Getting content…
 * "Getting content…" = "Getting content…";
 *
 * // Loading…
 * "Loading…" = "Loading…"
 *
 * // Point and scan
 * "Point and scan" = "Point and scan";
 *
 * // to view digital content
 * "to view digital content" = "to view digital content";
 *
 * // Point your phone
 * "Point your phone" = "Point your phone";
 *
 * // An error occurred
 * "An error occurred" = "An error occurred";
 *
 * // Async request failed
 * // Layer details request failed
 * // POI request failed
 * // Text action request failed
 * // Text action request to server failed
 * // We didn't receive a suitable response from our servers. You might want to check your network connection or try again later.
 * "We didn't receive a suitable response from our servers. You might want to check your network connection or try again later." = "We didn't receive a suitable response from our servers. You might want to check your network connection or try again later.";
 * @endcode
 
 */
