import tkinter as tk
from root_class import Root


if __name__ == '__main__':
    r = Root()
    r.create_frame_main()
    r.create_frame_paper_add()
    r.create_frame_paper_delete()
    r.create_frame_paper_modify()
    r.create_frame_paper_search()
    r.switch_to_frame("frame_main")
    r.root.mainloop()
