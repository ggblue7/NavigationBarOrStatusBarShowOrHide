//
//  NavBar&StatusBar.h
//  NavigationBarAndStatusBarShowOrHide
//
//  Created by blue on 14-4-14.
//  Copyright (c) 2014年 blue. All rights reserved.
//

#ifndef NavigationBarAndStatusBarShowOrHide_NavBar_StatusBar_h
#define NavigationBarAndStatusBarShowOrHide_NavBar_StatusBar_h

#define StatusBarStateChange_interface \
\
- (void)statusBarShow; \
- (void)statusBarHide; \
- (void)statusBarAutomatic;

#define StatusBarStateChange_implementation \
static BOOL _isHide; \
\
- (BOOL)prefersStatusBarHidden \
{ \
    return _isHide; \
} \
\
- (void)statusBarShow \
{ \
    _isHide = NO; \
    [self setNeedsStatusBarAppearanceUpdate]; \
} \
\
- (void)statusBarHide \
{ \
    _isHide = YES; \
    [self setNeedsStatusBarAppearanceUpdate]; \
} \
\
- (void)statusBarAutomatic \
{ \
    if (_isHide) { \
        [self statusBarShow]; \
    }else{ \
        [self statusBarHide]; \
    } \
}

#define NavBarStateChange_interface \
\
- (void)navBarShow:(CGFloat)duration; \
- (void)navBarHide:(CGFloat)duration; \
- (void)navBarAutomatic:(CGFloat)duration;

#define NavBarStateChange_implementation \
\
- (void)navBarShow:(CGFloat)duration \
{ \
    if (duration == 0) { \
        duration = 0.2f; \
    } \
    [UIView animateWithDuration:duration animations:^{ \
        self.navigationController.navigationBar.transform = CGAffineTransformIdentity; \
    }]; \
} \
\
- (void)navBarHide:(CGFloat)duration \
{ \
    if (duration == 0) { \
        duration = 0.2f; \
    } \
    [UIView animateWithDuration:duration animations:^{ \
        self.navigationController.navigationBar.transform = CGAffineTransformMakeTranslation(0, -64); \
    }]; \
} \
\
- (void)navBarAutomatic:(CGFloat)duration \
{ \
    if (self.navigationController.navigationBar.frame.origin.y < 20) { \
        [self navBarShow:duration]; \
    }else{ \
        [self navBarHide:duration]; \
    } \
}


#define NavBarAndStatusBarStateChange_interface \
StatusBarStateChange_interface \
NavBarStateChange_interface \
- (void)navBarAndStatusBarShow:(CGFloat)duration; \
- (void)navBarAndStatusBarHide:(CGFloat)duration; \
- (void)navBarAndStatusBarStateChangeAutomatic;

#define NavBarAndStatusBarStateChange_implementation \
StatusBarStateChange_implementation \
NavBarStateChange_implementation \
\
- (void)navBarAndStatusBarShow:(CGFloat)duration \
{ \
    if (duration == 0) { \
        duration = 0.2f; \
    } \
    [self navBarShow:duration]; \
    [self statusBarShow]; \
} \
\
- (void)navBarAndStatusBarHide:(CGFloat)duration \
{ \
    if (duration == 0) { \
        duration = 0.2f; \
    } \
    [self statusBarHide]; \
    [self navBarHide:duration]; \
} \
\
- (void)navBarAndStatusBarStateChangeAutomatic \
{ \
    if (self.navigationController.navigationBar.frame.origin.y < 20) { \
        [self navBarAndStatusBarShow:0]; \
    }else{ \
        [self navBarAndStatusBarHide:0]; \
    } \
}



#endif
