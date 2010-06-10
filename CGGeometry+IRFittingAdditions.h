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





CG_INLINE CGRect

CGGetInsetRectWithPadding(CGRect originalRect, CGFloat thePadding) {

	return CGRectMake(
	
		originalRect.origin.x + (1 * thePadding),
		originalRect.origin.y + (1 * thePadding),
		originalRect.size.width + (-2 * thePadding),
		originalRect.size.height + (-2 * thePadding)
	
	);

}





CG_INLINE CGPoint

CGGetCenterOfRect(CGRect theRect) {
	
	return CGPointMake(

		theRect.origin.x + (theRect.size.width / 2),
		theRect.origin.y + (theRect.size.height / 2)

	);
	
}





CG_INLINE CGPoint

CGGetRelativeMidPointOfRect(CGRect theRect) {
	
	return CGPointMake(
			   
		theRect.size.width / 2,
		theRect.size.height / 2

	);
	
}





CG_INLINE void

CGDumpRect(CGRect theRect, NSString *theMessage) {

	NSLog(@"%@ = (%f %f; %f %f)", theMessage, theRect.origin.x, theRect.origin.y, theRect.size.width, theRect.size.height);

}





CG_INLINE void

CGDumpPoint(CGPoint thePoint, NSString *theMessage) {

	NSLog(@"%@ = (%f %f)", theMessage, thePoint.x, thePoint.y);

}





#endif