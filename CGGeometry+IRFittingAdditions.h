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










# pragma mark Structures and Types





typedef enum {

	IRCGTranslateAlignTypeCenter,
	IRCGTranslateAlignTypeTop,
	IRCGTranslateAlignTypeTopRight,
	IRCGTranslateAlignTypeRight,
	IRCGTranslateAlignTypeBottomRight,
	IRCGTranslateAlignTypeBottom,
	IRCGTranslateAlignTypeBottomLeft,
	IRCGTranslateAlignTypeLeft,
	IRCGTranslateAlignTypeTopLeft
	
} IRCGTranslateAlignType;





typedef enum {
	
	IRCGFlippingFlagFlipped = YES,
	IRCGFlippingFlagUnflipped = NO	
	
} IRCGFlippingFlag;





typedef struct IRCGDelta {

	CGFloat x;
	CGFloat y;

} IRCGDelta;





typedef enum {
	
	IRCGEdgeTop,
	IRCGEdgeRight,
	IRCGEdgeBottom,
	IRCGEdgeLeft
	
} IRCGEdge;





typedef enum {
	
	IRCGBorderTypeInset,
	IRCGBorderTypeNormal,
	IRCGBorderTypeOutset
	
} IRCGBorderType;





struct IRCGLine {

	CGPoint origin;
	CGPoint destination;
	CGFloat width;
	UIColor *color;

}; typedef struct IRCGLine IRCGLine;





struct IRCGBorder {
	
	IRCGEdge edge;
	IRCGBorderType type;
	CGFloat width;
	UIColor *color;

}; typedef struct IRCGBorder IRCGBorder;





struct IRCGShadow {

	IRCGEdge edge;
	CGPoint offset;
	CGFloat spread;
	UIColor *color;
	
}; typedef struct IRCGShadow IRCGShadow;




















# pragma mark Introspection





CG_INLINE void IRCGDumpRect(CGRect theRect, NSString *theMessage) {
	
	NSLog(@"%@ = (%f %f; %f %f)", theMessage, theRect.origin.x, theRect.origin.y, theRect.size.width, theRect.size.height);
	
}





CG_INLINE void IRCGDumpSize(CGSize theSize, NSString *theMessage) {
	
	NSLog(@"%@ = (%f %f)", theMessage, theSize.width, theSize.height);
	
}





CG_INLINE void IRCGDumpPoint(CGPoint thePoint, NSString *theMessage) {
	
	NSLog(@"%@ = (%f %f)", theMessage, thePoint.x, thePoint.y);
	
}





CG_INLINE void IRCGDumpExtremes(CGRect theRect, NSString *theMessage) {
	
	NSLog(@"%@ = (%f %f %f; %f %f %f)", theMessage, 
	      
	      CGRectGetMinX(theRect),
	      CGRectGetMidX(theRect),
	      CGRectGetMaxX(theRect),
	      
	      CGRectGetMinY(theRect),
	      CGRectGetMidY(theRect),
	      CGRectGetMaxY(theRect)
	      
	);
	
}




















# pragma mark IRCGLine & IRCGBorder





CG_INLINE IRCGLine IRCGLineMake(CGPoint origin, CGPoint destination, CGFloat width, UIColor *color) {

	IRCGLine theLine;
	
	theLine.origin = origin;
	theLine.destination = destination;
	theLine.width = width;
	theLine.color = [color retain];
	
	return theLine;
	
}





CG_INLINE IRCGBorder IRCGBorderMake (IRCGEdge edge, IRCGBorderType type, CGFloat width, UIColor *color) {
	
	IRCGBorder theBorder;
	
	theBorder.edge = edge;
	theBorder.type = type;
	theBorder.width = width;
	theBorder.color = [color retain];
	
	return theBorder;
	
}




















# pragma mark IRCGShadow





CG_INLINE IRCGShadow IRCGShadowMake(IRCGEdge edge, CGPoint offset, CGFloat spread, UIColor *color) {

	IRCGShadow theShadow;
	
	theShadow.edge = edge;
	theShadow.offset = offset;
	theShadow.spread = spread;
	theShadow.color = [color retain];
	
	return theShadow;
	
}





















# pragma mark Fitting CGSizes & CGRects





CG_INLINE CGRect IRCGSizeGetCenteredInRect(CGSize enclosedSize, CGRect enclosingRect, CGFloat minimalPadding, IRCGFlippingFlag flipped) {

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





CG_INLINE CGRect IRCGRectGetInsetRect (CGRect originalRect, CGFloat thePadding) {

	return CGRectMake(
	
		originalRect.origin.x + (1 * thePadding),
		originalRect.origin.y + (1 * thePadding),
		originalRect.size.width + (-2 * thePadding),
		originalRect.size.height + (-2 * thePadding)
	
	);

}





CG_INLINE CGPoint IRCGRectGetGlobalMidXY(CGRect theRect) {
	
	return CGPointMake(

		theRect.origin.x + CGRectGetMaxX(theRect),
		theRect.origin.y + CGRectGetMaxY(theRect)

	);
	
}





CG_INLINE CGPoint IRCGRectGetLocalMidXY(CGRect theRect) {
	
	return CGPointMake(
			   
		theRect.size.width / 2,
		theRect.size.height / 2

	);
	
}




















# pragma mark Delta & Translating





CG_INLINE CGRect IRCGRectTranslate (CGRect theRect, CGFloat translateX, CGFloat translateY) {

	return CGRectMake(
	
		theRect.origin.x + translateX, 
		theRect.origin.y + translateY, 
		theRect.size.width, 
		theRect.size.height
		
	);

}






CG_INLINE IRCGDelta IRCGDeltaMake (CGFloat deltaX, CGFloat deltaY) {

	IRCGDelta delta;
	
	delta.x = deltaX;
	delta.y = deltaY;

	return delta;

}





CG_INLINE IRCGDelta IRCGDeltaMakeFromPoints (CGPoint origin, CGPoint destination) {

	IRCGDelta delta;

	delta.x = destination.x - origin.x;
	delta.y = destination.y - origin.y;

	return delta;

}




















# pragma mark Aligning & Scaling Rects





CG_INLINE CGRect IRCGRectAlignToRect (CGRect theRect, CGRect referenceRect, IRCGTranslateAlignType alignType, IRCGFlippingFlag flipped) {

	CGPoint originPoint;
	CGPoint destinationPoint;
	
	CGFloat (* processorX)(CGRect) = NULL;
	CGFloat (* processorY)(CGRect) = NULL;
	
	CGFloat (* processorYTop)(CGRect) = NULL;
	CGFloat (* processorYBottom)(CGRect) = NULL;
	
	
	if (flipped) {
		
		processorYTop = &CGRectGetMinY;
		processorYBottom = &CGRectGetMaxY;
		
	} else {
		
		processorYTop = &CGRectGetMaxY;
		processorYBottom = &CGRectGetMaxY;
		
	}
	
	
	switch (alignType) {

		case IRCGTranslateAlignTypeTopLeft:
		case IRCGTranslateAlignTypeLeft:
		case IRCGTranslateAlignTypeBottomLeft:
		
			processorX = &CGRectGetMinX;
			break;
			
		case IRCGTranslateAlignTypeTop:
		case IRCGTranslateAlignTypeCenter:
		case IRCGTranslateAlignTypeBottom:
		
			processorX = &CGRectGetMidX;
			break;
		
		case IRCGTranslateAlignTypeTopRight:
		case IRCGTranslateAlignTypeRight:
		case IRCGTranslateAlignTypeBottomRight:
		
			processorX = &CGRectGetMaxX;
			break;
			
	}
	
	
	switch (alignType) {

		case IRCGTranslateAlignTypeBottomLeft:
		case IRCGTranslateAlignTypeBottom:
		case IRCGTranslateAlignTypeBottomRight:
		
			processorY = processorYBottom;
			break;
			
		case IRCGTranslateAlignTypeLeft:
		case IRCGTranslateAlignTypeCenter:
		case IRCGTranslateAlignTypeRight:
		
			processorY = &CGRectGetMidY;
			break;
		
		case IRCGTranslateAlignTypeTopLeft:
		case IRCGTranslateAlignTypeTop:
		case IRCGTranslateAlignTypeTopRight:

			processorY = processorYTop;
			break;
			
	}
	
	
	originPoint = CGPointMake(processorX(theRect), processorY(theRect));
	destinationPoint = CGPointMake(processorX(referenceRect), processorY(referenceRect));
	
	IRCGDelta theDelta = IRCGDeltaMakeFromPoints(originPoint, destinationPoint);
	
	return IRCGRectTranslate(theRect, theDelta.x, theDelta.y);

}





CG_INLINE CGRect IRCGRectScale (CGRect theRect, CGFloat width, CGFloat height, IRCGTranslateAlignType alignType, BOOL flipped) {

	return IRCGRectAlignToRect(
	
		CGRectMake(
	
			theRect.origin.x, 
			theRect.origin.y, 
			width, 
			height
			
		),
	
		theRect, 
		alignType,
		flipped
		
	);

}





#endif