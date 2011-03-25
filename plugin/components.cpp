/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include "components.h"
#include "fingerpaint.h"

void components::registerTypes(const char *uri)
{
    qmlRegisterType<Fingerpaint>(uri, 0, 1, "Fingerpaint");
}

Q_EXPORT_PLUGIN(components);
