

#include "ModuloNode.h"

#include <maya/MPlug.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MGlobal.h>
#include <maya/MFnNumericAttribute.h>
#include <cmath>


MTypeId Modulo::id( 0x00121BD2 );
MObject Modulo::input;
MObject Modulo::modulus;
MObject Modulo::output;


Modulo::Modulo() {}

Modulo::~Modulo() {}

void* Modulo::creator() {
	return new Modulo();
}


MStatus Modulo::initialize() {
	// attributes are writable by default
	// attributes are storable by default
	// attributes are readable by default
	// attributes not keyable by default

	MStatus stat;
	MFnNumericAttribute fnNum;

	input = fnNum.create("input", "in", MFnNumericData::kDouble, 0.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);
	stat = Modulo::addAttribute(input);
	CHECK_MSTATUS(stat);

	modulus = fnNum.create("modulus", "mod", MFnNumericData::kDouble, 0.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setKeyable(true);
	stat = Modulo::addAttribute(modulus);
	CHECK_MSTATUS(stat);

	output = fnNum.create("output", "out", MFnNumericData::kDouble, 0.0, &stat);
	CHECK_MSTATUS(stat);
	fnNum.setStorable(false);
	fnNum.setWritable(false);
	stat = Modulo::addAttribute(output);
	CHECK_MSTATUS(stat);

	Modulo::attributeAffects(input, output);
	Modulo::attributeAffects(modulus, output);

	return MS::kSuccess;
}


MStatus Modulo::compute( const MPlug& plug, MDataBlock& data ) {
	if (plug != output)
		return MS::kUnknownParameter;

	data.outputValue(Modulo::output).setDouble( std::fmod(data.inputValue(Modulo::input).asDouble(),
														  data.inputValue(Modulo::modulus).asDouble()) );

	data.setClean(output);

	return MS::kSuccess;
}





