#include <vector>
#include <string>
#include <midi/midi.h>
#include <iostream>
#include <cstdlib>

#define RANDOM() ((float) rand() / RAND_MAX)

#include "ImprovisationAlgorithm.h"
#include "Swing8.h"
#include "RockDrum.h"
#include "RandomSoloist.h"
#include "Options.h"
#include "Message.h"
#include "Instrument.h"
#include "Sequencer.h"

