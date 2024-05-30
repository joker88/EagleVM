#pragma once
#include "eaglevm-core/virtual_machine/ir/x86/base_handler_gen.h"
#include "eaglevm-core/virtual_machine/ir/x86/base_x86_translator.h"

namespace eagle::ir::handler
{
    class add : public base_handler_gen
    {
    public:
        add();
        ir_insts gen_handler(handler_sig signature) override;
    };
}

namespace eagle::ir::lifter
{
    class add : public base_x86_translator
    {
        using base_x86_translator::base_x86_translator;

        translate_mem_result translate_mem_action(const codec::dec::op_mem& op_mem, uint8_t idx);
        translate_status encode_operand(codec::dec::op_imm op_imm, uint8_t idx) override;
        void finalize_translate_to_virtual() override;
    };
}