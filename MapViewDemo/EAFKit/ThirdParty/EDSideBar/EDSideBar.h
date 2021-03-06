//
//  ECSideBar.h
//
//
//  Created by erndev 
//  BSD license. 
//

#import <Cocoa/Cocoa.h>

@class EDSideBar;

#if __has_feature(objc_arc)	
#define EDSideBarRetain nonatomic, strong
#define EDSideBarAssign nonatomic, unsafe_unretained
#else
#define EDSideBarRetain nonatomic, retain
#define EDSideBarAssign nonatomic, assign
#endif

@protocol EDSideBarDelegate <NSObject>
@optional
- (void)sideBar:(EDSideBar*)tabBar didSelectButton:(NSInteger)index fromClick:(BOOL)fromClick;
@end

enum {
	ECSideBarLayoutTop			= 0,
	ECSideBarLayoutCenter		= 1,
	ECSideBarLayoutBottom		= 2,
};	
typedef NSUInteger ECSideBarLayoutMode;

@interface EDSideBar : NSView
{
	ECSideBarLayoutMode layoutMode;
	NSColor *_backgroundColor;
	CGFloat	buttonsHeight;
	NSMatrix *_matrix;
	Class cellClass;
	NSImageView *selectorImageView;
	BOOL	animateSelection;
	NSTimeInterval animationDuration;

}
-(void)setLayoutMode:(ECSideBarLayoutMode)layout;
-(void)addButtonWithTitle:(NSString*)title;
-(void)addButtonWithTitle:(NSString*)title image:(NSImage*)image;
-(void)addButtonWithTitle:(NSString*)title image:(NSImage*)image alternateImage:(NSImage*)alternateImage;
-(void)setTarget:(id)aTarget withSelector:(SEL)aSelector atIndex:(NSInteger)anIndex;
-(void)selectButtonAtRow:(NSUInteger)row;
-(void)selectNext;
-(void)selectPrev;
-(void)drawBackground:(NSRect)rect;
-(void)setSelectionImage:(NSImage*)image;
-(id)cellForItem:(NSInteger)index;
-(NSInteger)selectedIndex;
-(CGRect)frameForButtonAtIndex:(NSInteger)index;
-(NSMatrix*)matrix;

@property (EDSideBarRetain) NSColor *backgroundColor;
@property (nonatomic, weak) id<EDSideBarDelegate>sidebarDelegate;
@property (EDSideBarAssign,setter=setCellClass:) Class cellClass;
@property (nonatomic, setter=setLayoutMode:) ECSideBarLayoutMode layoutMode;
@property (nonatomic, setter=setButtonsHeight:) CGFloat buttonsHeight;
@property BOOL animateSelection;
@property NSTimeInterval animationDuration;
@property CGFloat noiseAlpha;   
@end
