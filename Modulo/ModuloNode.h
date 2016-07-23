#pragma once

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h> 

 
class Modulo : public MPxNode {
public:
	Modulo();
	virtual ~Modulo();
	static void* creator();
	static MStatus initialize();
	virtual MPxNode::SchedulingType schedulingType() const override { return MPxNode::kParallel; };
	virtual MStatus compute( const MPlug& plug, MDataBlock& data );
public:
	static MTypeId id;
	static MObject input;
	static MObject modulus;
	static MObject output;
};
