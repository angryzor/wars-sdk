#pragma once
#include <ucsl/colors.h>

namespace csl::ut {
    UCSL_NEWTYPE_STRUCT(Color8, ucsl::colors::Color8RGBA, Color8RGBA);
    UCSL_NEWTYPE_STRUCT(Colorf, ucsl::colors::ColorfRGBA, ColorfRGBA);
}
