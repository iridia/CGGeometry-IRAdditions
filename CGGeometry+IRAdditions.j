//	CGGeometry+IRAdditions.j
//	Evadne Wu at Iridia,2010





/* (CGPoint) */ function CGPointOffset (aPoint, offsetX, offsetY) {
	
	return CGPointMake (
	
		aPoint.x + offsetX,
		aPoint.y + offsetY
		
	);
	
} 





/* (CGRect) */ function CGRectInsetFromEdges (aRect, offsetTop, offsetRight, offsetBottom, offsetLeft) {

	return CGRectMake(
	
		aRect.origin.x - offsetLeft,
		aRect.origin.y - offsetBottom,
		aRect.size.width + offsetLeft + offsetRight,
		aRect.size.height + offsetBotttom + offsetTop
	
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
	
	
	
	
	