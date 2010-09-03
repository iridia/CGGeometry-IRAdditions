//	CGGeometry+IRFittingAdditions.j
//	Evadne Wu at Iridia,2010





/* (CGRect) */ function CGRectInsetFromEdges (aRect, offsetTop, offsetRight, offsetBottom, offsetLeft) {

	return CGRectMake(
	
		aRect.origin.x - offsetLeft,
		aRect.origin.y - offsetBottom,
		aRect.size.width + offsetLeft + offsetRight,
		aRect.size.height + offsetBotttom + offsetTop,
	
	);

}




