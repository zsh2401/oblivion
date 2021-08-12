#import<Foundation/Foundation.h>
#import "ff/ff.h"
int main(){	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSLog(@"Programming Object-C!");
	NSLog(@"How are you!");
	[pool drain];
	return add(1,5);
}
