#include "eaglevm-core/virtual_machine/il/x86/handlers/inc.h"

#include "eaglevm-core/virtual_machine/il/commands/cmd_rflags_load.h"
#include "eaglevm-core/virtual_machine/il/commands/cmd_rflags_store.h"

namespace eagle::il::handler
{
    inc::inc()
    {
        entries = {
            { codec::gpr_64, 1 },
            { codec::gpr_32, 1 },
            { codec::gpr_16, 1 },
        };
    }

    il_insts inc::gen_handler(const codec::reg_class size, uint8_t operands)
    {
        const il_size target_size = static_cast<il_size>(get_reg_size(size));
        const reg_vm vtemp = get_bit_version(reg_vm::vtemp, target_size);

        return {
            std::make_shared<cmd_vm_pop>(vtemp, target_size),
            std::make_shared<cmd_x86_dynamic>(codec::m_dec, vtemp),
            std::make_shared<cmd_vm_push>(vtemp, target_size)
        };
    }
}

void eagle::il::lifter::inc::finalize_translate_to_virtual()
{
    block->add_command(std::make_shared<cmd_rflags_load>());
    base_x86_lifter::finalize_translate_to_virtual();
    block->add_command(std::make_shared<cmd_rflags_store>());
}
