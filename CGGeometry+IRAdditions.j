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
		aRect.size.height + offsetBotttom + offsetTop,
	
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




	