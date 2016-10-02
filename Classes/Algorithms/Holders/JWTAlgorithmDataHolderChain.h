//
//  JWTAlgorithmDataHolderChain.h
//  JWT
//
//  Created by Lobanov Dmitry on 02.10.16.
//  Copyright © 2016 Karma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWTAlgorithmDataHolder.h"

@interface JWTAlgorithmDataHolderChain : NSObject

@property (strong, nonatomic, readonly) NSArray *holders;

#pragma mark - Initialization
- (instancetype)initWithHolders:(NSArray *)holders;
- (instancetype)initWithHolder:(id<JWTAlgorithmDataHolder>)holder;

#pragma mark - Appending
- (instancetype)chainByAppendingChain:(JWTAlgorithmDataHolderChain *)chain;
- (instancetype)chainByAppendingHolders:(NSArray *)holders;
- (instancetype)chainByAppendingHolder:(id<JWTAlgorithmDataHolder>)holder;

@end

@interface JWTAlgorithmDataHolderChain (HoldersPopulation)
- (NSArray *)singleAlgorithm:(id<JWTAlgorithm>)algorithm withManySecretData:(NSArray *)secretsData;
- (NSArray *)singleSecretData:(NSData *)secretData withManyAlgorithms:(NSArray *)algorithms;

- (instancetype)chainByPopulatingAlgorithm:(id<JWTAlgorithm>)algorithm withManySecretData:(NSArray *)secretsData;
- (instancetype)chainByPopulatingSecretData:(NSData *)secretData withManyAlgorithms:(id<JWTAlgorithm>)algorithms;

@end
