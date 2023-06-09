from root_class import Root


if __name__ == '__main__':
    r = Root()
    r.create_frame_main()
    r.create_frame_paper_add()
    r.create_frame_paper_delete()
    r.create_frame_paper_modify()
    r.create_frame_paper_check()

    r.create_frame_proj_add()
    r.create_frame_proj_delete()
    r.create_frame_proj_modify()
    r.create_frame_proj_check()

    r.create_frame_course_add()
    r.create_frame_course_delete()
    r.create_frame_course_modify()
    r.create_frame_course_check()

    r.create_frame_statistic()
    r.switch_to_frame("frame_main")
    r.root.mainloop()
