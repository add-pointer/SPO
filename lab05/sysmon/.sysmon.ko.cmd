cmd_/home/debian/lab_05/lab05_kmods/sysmon/sysmon.ko := ld -r -m elf_x86_64 -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T arch/x86/module.lds -o /home/debian/lab_05/lab05_kmods/sysmon/sysmon.ko /home/debian/lab_05/lab05_kmods/sysmon/sysmon.o /home/debian/lab_05/lab05_kmods/sysmon/sysmon.mod.o;  true