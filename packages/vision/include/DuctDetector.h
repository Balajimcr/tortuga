/*
 * Copyright (C) 2008 Robotics at Maryland
 * Copyright (C) 2008 Chris Giles
 * All rights reserved.
 *
 * Author: Chris Giles <cgiles17@umd.edu>
 * File:  packages/vision/include/DuctDetector.h
 */

#ifndef RAM_DUCT_DETECTOR_H_07_03_2008
#define RAM_DUCT_DETECTOR_H_07_03_2008

#include "cv.h"
#include "vision/include/Common.h"
#include "vision/include/Detector.h"
#include "core/include/ConfigNode.h"
#include "vision/include/BlobDetector.h"

#include "vision/include/Export.h"

namespace ram {
namespace vision {

class RAM_EXPORT DuctDetector : public Detector
{
public:
    DuctDetector(core::ConfigNode config,
                 core::EventHubPtr eventHub = core::EventHubPtr());
    DuctDetector(core::EventHubPtr eventHub = core::EventHubPtr());
	virtual ~DuctDetector();
        
    void processImage(Image* input, Image* output = 0);

    /** Normalized from -1 to 1*/
    double getX();
    
    /** Normalized from -1 to 1*/
    double getY();
    
    /** 0 at the closest 1 at the father */
    double getRange();
    
    double getRotation();
    
    bool getVisible();
    bool getAligned();
    bool blobsAreClose(BlobDetector::Blob b1, BlobDetector::Blob b2,
                       double growThreshX,double growThreshY);
                       
    void mergeBlobs(std::vector<BlobDetector::Blob>* blobsToMerge, std::vector<BlobDetector::Blob>* mergedBlobs, double growThreshX, double growThreshY, double minXOverYForStretching);
    
private:
    void init(core::ConfigNode config);
    inline int yellow(unsigned char r, unsigned char g, unsigned char b);
    
    BlobDetector::Blob fullDuct;
    BlobDetector blobDetector;
    Image* m_working;
    Image* m_workingPercents;
    Image* m_blackMasked;
    Image* m_yellowMasked;

    double m_x, m_y, m_rotation, n_x, n_y, m_range;

    // Configurable variables
    double m_minRedOverGreen;
    double m_maxRedOverGreen;
    double m_minRedOverBlue;
    double m_minGreenOverBlueOnRedFailureForInsideDuct;
    int m_erodeIterations;
    double m_alignedThreshold;
    int m_centerAlignedThreshold;

    // More member variables
    bool m_found;
    bool containsOne;
};

} // namespace vision
} // namespace ram

#endif // RAM_DUCT_DETECTOR_H_07_03_2008

