const std = @import("std");
const builtin = std.builtin;
const fs = std.fs;
const heap = std.heap;
const io = std.io;
const os = std.os;

const stdout = io.getStdOut().writer();
const stderr = io.getStdErr().writer();

pub fn main() void {
    var arena = heap.ArenaAllocator.init(heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    const home_dir = os.getenv("HOME").?;
    const file_path = fs.path.join(allocator, &[_][]const u8{ home_dir, ".bashrc" }) catch |e| handleErr(e);
    const file = fs.openFileAbsolute(file_path, .{}) catch |e| handleErr(e);
    defer file.close();
    const result = file.readToEndAlloc(allocator, 4 * 1024);
    stdout.print("{s}\n", .{result}) catch |e| handleErr(e);
}

fn handleErr(v: anyerror) noreturn {
    stderr.print("{s}\n", .{@errorName(v)}) catch unreachable;
    os.exit(1);
}
