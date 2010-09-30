//	CGGeometry+IRAdditions.j
//	Evadne Wu at Iridia,2010





/* (CGPoint) */ function CGPointOffset (aPoint, offsetX, offsetY) {
	
	return CGPointMake (
	
		aPoint.x + offsetX,
		aPoint.y + offsetY
		
	);
	
}





kCGAlignmentPointRefMinXMask = 1 << 0;
kCGAlignmentPointRefMidXMask = 1 << 1;
kCGAlignmentPointRefMaxXMask = 1 << 2;
kCGAlignmentPointRefMinYMask = 1 << 3;
kCGAlignmentPointRefMidYMask = 1 << 4;
kCGAlignmentPointRefMaxYMask = 1 << 5;

kCGAlignmentPointRefTopLeft = kCGAlignmentPointRefMinXMask | kCGAlignmentPointRefMinYMask;
kCGAlignmentPointRefTop = kCGAlignmentPointRefMidXMask | kCGAlignmentPointRefMinYMask;
kCGAlignmentPointRefTopRight = kCGAlignmentPointRefMaxXMask | kCGAlignmentPointRefMinYMask;
kCGAlignmentPointRefLeft = kCGAlignmentPointRefMinXMask | kCGAlignmentPointRefMidYMask;
kCGAlignmentPointRefCenter = kCGAlignmentPointRefMidXMask | kCGAlignmentPointRefMidYMask;
kCGAlignmentPointRefRight = kCGAlignmentPointRefMaxXMask | kCGAlignmentPointRefMidYMask;
kCGAlignmentPointRefBottomLeft = kCGAlignmentPointRefMinXMask | kCGAlignmentPointRefMaxYMask;
kCGAlignmentPointRefBottom = kCGAlignmentPointRefMidXMask | kCGAlignmentPointRefMaxYMask;
kCGAlignmentPointRefBottomRight = kCGAlignmentPointRefMaxXMask | kCGAlignmentPointRefMaxYMask;

/* (CGRect) */ function CGAlignedRectMake ( /* (CGRect) */ movedRect, /* (kCGAlignmentPointRef) */ movedPointRef, /* (CGRect) */ referenceRect, /* (kCGAlignmentPointRef) */ referencePointRef) {
	
	var fromPoint = CGPointFromPointRefInRect(movedRect, movedPointRef);
	var toPoint = CGPointFromPointRefInRect(referenceRect, referencePointRef);
	
	return CGRectTranslate(
		
		movedRect,
		CGDeltaMake(fromPoint, toPoint)
		
	);
	
}





/* (CGPoint) */ function CGPointFromPointRefInRect ( /* (CGRect) */ aRect, /* (CGAlignmentPointRef) */ pointRef) {
	
	var responseX = 0;
	if (pointRef & kCGAlignmentPointRefMinXMask) responseX += CGRectGetMinX(aRect);
	if (pointRef & kCGAlignmentPointRefMidXMask) responseX += CGRectGetMidX(aRect);
	if (pointRef & kCGAlignmentPointRefMaxXMask) responseX += CGRectGetMaxX(aRect);
	
	var responseY = 0;
	if (pointRef & kCGAlignmentPointRefMinYMask) responseY += CGRectGetMinY(aRect);
	if (pointRef & kCGAlignmentPointRefMidYMask) responseY += CGRectGetMidY(aRect);
	if (pointRef & kCGAlignmentPointRefMaxYMask) responseY += CGRectGetMaxY(aRect);
	
	return CGPointMake(responseX, responseY);
	
}





/* (CGPoint) */ function CGPointCenterOfPoints () {
	
	if (arguments.length == 0) return CGPointMakeZero();
	
	var x = 0, y = 0; for(var i = 0; i < arguments.length; i++) {
		
		x += arguments[i].x;
		y += arguments[i].y;
		
	}
	
	return CGPointMake(x / i, y / i);
	
}





/* (CGRect) */ function CGRectInsetFromEdges (aRect, offsetTop, offsetRight, offsetBottom, offsetLeft) {

	return CGRectMake(
	
		aRect.origin.x - offsetLeft,
		aRect.origin.y - offsetTop,
		aRect.size.width + offsetLeft + offsetRight,
		aRect.size.height + offsetBottom + offsetTop
	
	);

}

/* (CGRect) */ function CGRectOffset (aRect, anOffset) {

	return CGRectInsetFromEdges(aRect, anOffset.topOffset, anOffset.rightOffset, anOffset.bottomOffset, anOffset.leftOffset)

}





/* (CGRect) */ function CGRectTranslate (aRect, aDelta) {
	
	return CGRectMake(
	
		aRect.origin.x + aDelta.x,
		aRect.origin.y + aDelta.y,
		aRect.size.width,
		aRect.size.height
		
	);
	
}





/* (void) */ function CGRectDump (aRect, optionalText) {

	CPLog(
		
		((!!optionalText ? optionalText + @" — " : @"") + @" — %f by %f at %f, %f"), 
	
		aRect.size.width,
		aRect.size.height,
		aRect.origin.x,
		aRect.origin.y
	
	);

}

/* (void) */ function CGPointDump (aPoint, optionalText) {

	CPLog(
		
		((!!optionalText ? optionalText + @" — " : @"") + @" — %f, %f"), 
	
		aPoint.x,
		aPoint.y
	
	);

}





//!	Borders

	kCGBorderTypeNormal = "kCGBorderTypeNormal";
	kCGBorderTypeInset = "kCGBorderTypeInset";
	kCGBorderTypeOutset = "kCGBorderTypeOutset";
	
	/* (CGBorder) */ function CGBorderMake ( /* (CGBorderType) */ type, /* (CGFloat) */ thickness,  /* (CGFloat) */ offsetFromCenter, /* (CGFloat) */ opacity) {

		return {
		
			type: type,
			thickness: thickness,
			offset: offsetFromCenter,
			opacity: opacity
		
		};

	}





//!	Deltas

	/* (CGDelta) */ function CGDeltaMake (fromPoint, toPoint) {
		
		return {
			
			x: toPoint.x - fromPoint.x,
			y: toPoint.y - fromPoint.y			
		
		}

	}
	
	
	
	
	/* (CGPoint) */ function CGPointOffset (thePoint, offsetDelta, invert) {

		if (!invert) invert = false;
		
		var ratio = invert ? -1 : 1;
		
		return CGPointMake(
		
			thePoint.x + offsetDelta.x * ratio,
			thePoint.y + offsetDelta.y * ratio
			
		);

	}
	
	
	
	
	
	/* (CGRectOffset) */ function CGRectOffsetMake (topOffset, rightOffset, bottomOffset, leftOffset) {
		
		return {
			
			"topOffset": topOffset,
			"rightOffset": rightOffset,
			"bottomOffset": bottomOffset,
			"leftOffset": leftOffset
			
		};
		
	}
	
	/* (CGRectOffset) */ function CGRectOffsetInvert (offset) {
		
		return CGRectOffsetMake(
			
			-1 * offset.topOffset,
			-1 * offset.rightOffset,
			-1 * offset.bottomOffset,
			-1 * offset.leftOffset
			
		)
		
	}
	
	/* (CGRectOffset) */ function CGRectOffsetZero () {
		
		return CGRectOffsetMake(0, 0, 0, 0);
		
	}
	
	
	
	
	