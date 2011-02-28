// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OEI_O_S_FRAME_H_
#define _OEI_O_S_FRAME_H_

#include <Display/IFrame.h>
#include <Display/ICanvas.h>
#include <Meta/iOS.h>
#include <Devices/iOSTouch.h>

namespace OpenEngine {
namespace Display {

/**
 * Short description.
 *
 * @class iOSFrame iOSFrame.h ons/iOS/Display/iOSFrame.h
 */
class iOSFrame : public IFrame {
private:
    class FrameCanvas: public ICanvas {
    private:
        IFrame& frame;
    public:
        FrameCanvas(IFrame& frame): frame(frame) {}
        virtual ~FrameCanvas() {}
        unsigned int GetWidth() const { return frame.GetWidth(); }
        unsigned int GetHeight() const { return frame.GetHeight(); }
        void SetWidth(const unsigned int width) { frame.SetWidth(width); }
        void SetHeight(const unsigned int height) { frame.SetHeight(height); }

        void Handle(Display::InitializeEventArg arg) {}
        void Handle(Display::DeinitializeEventArg arg) {}
        void Handle(Display::ProcessEventArg arg) {}
        void Handle(Display::ResizeEventArg arg) {}

        ITexture2DPtr GetTexture() { return ITexture2DPtr(); }
    };

    ICanvas* canvas;
    FrameCanvas fc;
    id window;
    id view;

public:
    iOSFrame();
    bool IsFocused() const;

    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    unsigned int GetDepth() const;

    FrameOption GetOptions() const;
    bool GetOption(const FrameOption option) const;

    void SetWidth(const unsigned int width);
    void SetHeight(const unsigned int height);
    void SetDepth(const unsigned int depth);
    void SetOptions(const FrameOption options);
    void ToggleOption(const FrameOption option);

    void Handle(Core::InitializeEventArg arg);
    void Handle(Core::ProcessEventArg arg);
    void Handle(Core::DeinitializeEventArg arg);

    void SetCanvas(ICanvas* canvas) { this->canvas = canvas; }
    ICanvas* GetCanvas() { return canvas; }
    
    void SetTouch(Devices::iOSTouch*);
    
};

} // NS Display
} // NS OpenEngine

#endif // _OEI_O_S_FRAME_H_
