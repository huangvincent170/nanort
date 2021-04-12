module intersector
(
    input reset,
    input[:0] min_t,
    input[] max_t,
    input[] bmin0,
    input[] bmin1,
    input[] bmin2,
    input[] bmax0,
    input[] bmax1,
    input[] bmax2,
    input[] ray_org0,
    input[] ray_org1,
    input[] ray_org2,
    input[] ray_inv_dir0,
    input[] ray_inv_dir1,
    input[] ray_inv_dir2,
    input[] ray_dir_sign0,
    input[] ray_dir_sign1,
    input[] ray_dir_sign2,

    output[] tmin;
    output[] tmax;
    
);

assign out_dummy = reset ? 0 : in_dummy + 1;

assign min_x = ray_dir_sign0 ? bmax0 : bmin0;
assign min_y = ray_dir_sign1 ? bmax1 : bmin1;
assign min_z = ray_dir_sign2 ? bmax2 : bmin2;
assign max_x = ray_dir_sign0 ? bmin0 : bmax0;
assign max_y = ray_dir_sign1 ? bmin1 : bmax1;
assign max_z = ray_dir_sign2 ? bmin2 : bmax2;

// X
assign tmin_x = (min_x - ray_org0) * ray_inv_dir0;
// MaxMult robust BVH traversal(up to 4 ulp).
// 1.0000000000000004 for double precision.
assign tmax_x = (max_x - ray_org0) * ray_inv_dir0 * 1.00000024f;

// Y
assign tmin_y = (min_y - ray_org1) * ray_inv_dir1;
assign tmax_y = (max_y - ray_org1) * ray_inv_dir1 * 1.00000024f;

// Z
assign tmin_z = (min_z - ray_org2) * ray_inv_dir2;
assign tmax_z = (max_z - ray_org2) * ray_inv_dir2 * 1.00000024f;

assign tmin = safemax(tmin_z, safemax(tmin_y, safemax(tmin_x, min_t)));
assign tmax = safemin(tmax_z, safemin(tmax_y, safemin(tmax_x, max_t)));

initial begin
    $display("Hello World!");
    $finish;
end
endmodule

