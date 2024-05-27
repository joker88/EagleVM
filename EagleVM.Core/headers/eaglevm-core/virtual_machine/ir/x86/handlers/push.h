#pragma once
#include "eaglevm-core/virtual_machine/ir/x86/base_handler_gen.h"
#include "eaglevm-core/virtual_machine/ir/x86/base_x86_translator.h"

namespace eagle::ir::handler
{
    class push : public base_handler_gen
    {
    public:
        push();
    };
}

namespace eagle::ir::lifter
{
    class push : public base_x86_translator
    {
        using base_x86_translator::base_x86_translator;

        bool virtualize_as_address(codec::dec::operand operand, uint8_t idx) override;
        bool skip(uint8_t idx) override;

        void finalize_translate_to_virtual() override;
    };
}