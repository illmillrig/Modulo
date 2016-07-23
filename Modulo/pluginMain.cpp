

#include "ModuloNode.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "Travis Miller", "2016", "Any");

	status = plugin.registerNode( "Modulo", Modulo::id, Modulo::creator,
								  Modulo::initialize );
	if (!status) {
		status.perror("registerNode");
		return status;
	}

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );

	status = plugin.deregisterNode( Modulo::id );
	if (!status) {
		status.perror("deregisterNode");
		return status;
	}

	return status;
}
