//
//  SXNSDataAdditions.h
//  Sparrow Particle System Extension
//
//  Created by Daniel Sperl on 04.06.11.
//  Copyright 2011 Gamua. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the Simplified BSD License.
//

#import <Foundation/Foundation.h>

/** ------------------------------------------------------------------------------------------------
 
 Additions to the NSData class supporting Base64 and GZip en- and decoding. These methods are based
 on work of other authors; links to the origins are provided. 
 
 This class might become part of the next Sparrow release! If you encounter errors about duplicate
 definitions, you might not need it any longer and can simply remove it.
 
------------------------------------------------------------------------------------------------- */

@interface NSData (SXNSDataExtensions)

+ (NSData *)dataWithUncompressedContentsOfFile:(NSString *)file;

// -------------------------------------------------------------------------------------------------
// Copyright 2008 Kaliware, LLC. All rights reserved.
// Found here: http://idevkit.com/forums/tutorials-code-samples-sdk/8-nsdata-base64-extension.html
// -------------------------------------------------------------------------------------------------
+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
- (id)initWithBase64EncodedString:(NSString *)string;

- (NSString *)base64Encoding;
- (NSString *)base64EncodingWithLineLength:(uint)lineLength;

// -------------------------------------------------------------------------------------------------
// Copyright 2007 theidiotproject. All rights reserved.
// Found here: http://code.google.com/p/drop-osx/source/browse/trunk/Source/NSData%2Bgzip.h
// Also Check: http://deusty.blogspot.com/2007/07/gzip-compressiondecompression.html
// -------------------------------------------------------------------------------------------------
- (NSData *)gzipDeflate;
- (NSData *)gzipInflate;

@end
