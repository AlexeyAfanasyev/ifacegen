/**
*	Created by Evgeny Kamyshanov on March, 2014
*	Copyright (c) 2013-2014 BEFREE Ltd. 
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in
*	all copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*	THE SOFTWARE.
**/

#import <Foundation/Foundation.h>
#import "IFTransport.h"

extern NSString* const IFHTTPTransportErrorDomain;

typedef NS_ENUM(NSInteger, IFHTTPMethod) {
	IFHTTPMETHOD_AUTO,
    IFHTTPMETHOD_GET,
    IFHTTPMETHOD_HEAD,
    IFHTTPMETHOD_POST,
    IFHTTPMETHOD_PUT,
    IFHTTPMETHOD_DELETE,
    IFHTTPMETHOD_PATCH,
    IFHTTPMETHOD_OPTIONS,
    IFHTTPMETHOD_TRACE
};

@interface IFHTTPTransport : NSObject<IFTransport>

- (id)initWithURL:(NSURL*)url;

- (void)setUrlParams:(NSDictionary*)params;
- (NSHTTPURLResponse*)currentResponse;

- (BOOL)writeAll:(NSData*)data endpoint:(NSString*)endpoint method:(IFHTTPMethod)method error:(NSError* __autoreleasing*)error;

@property (nonatomic) NSInteger retriesCount;
@property (nonatomic) NSString* userAgent;

@end
