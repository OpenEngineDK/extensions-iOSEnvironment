
# Create the extension library
ADD_LIBRARY(Extensions_iOSEnvironment
  Core/iOSEngine.h
  Core/iOSEngine.mm
  Core/OEDelegate.h
  Core/OEDelegate.mm
  Display/OEViewController.h
  Display/OEViewController.mm
  Display/OEView.h
  Display/OEView.mm
  Display/iOSEnvironment.h
  Display/iOSEnvironment.mm
  Display/iOSFrame.h
  Display/iOSFrame.mm
  Devices/iOSTouch.h
  Devices/iOSTouch.cpp
)

TARGET_LINK_LIBRARIES(
  Extensions_iOSEnvironment
  "-framework QuartzCore"
)
