//
//  CGGeometry+IRFittingAdditions.h
//  Tarotie
//
//  Created by Evadne Wu on 6/1/10.
//  Copyright 2010 Iridia Productions. All rights reserved.
//





#ifndef CGGEOMETRY_IRIDIA_FITTING_ADDITIONS_
#define CGGEOMETRY_IRIDIA_FITTING_ADDITIONS_

#include <CoreGraphics/CGBase.h>
#include <CoreFoundation/CFDictionary.h>





CG_INLINE CGRect

CGFitSizeInRectWithPadding(CGSize enclosedSize, CGRect enclosingRect, CGFloat minimalPadding) {

	float enclosedRectAspectRatio = enclosedSize.width / enclosedSize.height;
	
	
	
	
	
	CGSize maximumEnclosedSizeSize = CGSizeMake(
					    
		enclosingRect.size.width - (2 * minimalPadding),
		enclosingRect.size.height - (2 * minimalPadding)
    
	);
	
	CGSize currentEnclosedSizeSize = CGSizeMake(
	
		enclosedSize.width,
		enclosedSize.height
	
	);
	
	
	
	
	
	if (currentEnclosedSizeSize.width > maximumEnclosedSizeSize.width)
	currentEnclosedSizeSize = CGSizeMake(
	
		maximumEnclosedSizeSize.width,
		maximumEnclosedSizeSize.width / enclosedRectAspectRatio
		
	);
	
	if (currentEnclosedSizeSize.height > maximumEnclosedSizeSize.height)
	currentEnclosedSizeSize = CGSizeMake(
	
		maximumEnclosedSizeSize.height * enclosedRectAspectRatio, 
		maximumEnclosedSizeSize.height
	
	);
	
	
	return CGRectMake(
				
		enclosingRect.origin.x + ((enclosingRect.size.width - currentEnclosedSizeSize.width) / 2), 
		enclosingRect.origin.y + ((enclosingRect.size.height - currentEnclosedSizeSize.height) / 2), 
		currentEnclosedSizeSize.width, 
		currentEnclosedSizeSize.height
				
	);

}





#endif