# New ports collection makefile for:	xclasses
# Date created:		2000-10-01
# Whom:			trevor
#
# $FreeBSD$
#

PORTNAME=	xclasses
PORTVERSION=	1.4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xcmail
DISTNAME=	Xclasses-public-${PORTVERSION}.src

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	C++ layout library for X

INSTALLS_SHLIB=	yes
NOT_FOR_ARCHS=	alpha amd64 ia64 sparc64
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	VERSION="${PORTVERSION}"
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/xclasses

post-patch:
.for file in build System/ARules.FreeBSD
	@${PERL} -pi \
		-e "s|%%CXX%%|${CXX}|g;" \
		-e "s|%%CXXFLAGS%%|${CXXFLAGS}|g;" \
		-e "s|%%X11BASE%%|${X11BASE}|g;" ${WRKSRC}/${file}
.endfor

do-build:
	@cd ${WRKSRC} && ${SH} build all

pre-install:
	${ECHO_CMD} bin/setenvxc > ${PLIST}
.for ii in \
Ddraw XCprogram Xclasses Xclasses_class Xcolors Xdisplay Xshadow Xwindows anim \
appwindow autotextbox bordergroup button callable card checkbox choice \
colornamegroup config creater dirview dlist easy_dialog fbutton file_dialog \
fileinput fontgroup gadget gfx_arrow gfx_autotext gfx_checkbox gfx_command \
gfx_dir gfx_file gfx_knob gfx_locked gfx_object gfx_text gfx_xpm go_button \
go_selbutton gpopup graphic group html_gadget htmltextbox image indicator \
input keyclass lefttext listgroup listview menu message message_tools \
multilistview mxbutton mxgadget mxknob output popbutton popup rubbergroup \
ruler scroller selbutton selgadget selknob slider spacegroup text textbox \
tools treeview types visible xclock
	${ECHO_CMD} include/Xclasses/${ii}.h >> ${PLIST}
.endfor
.for ii in .a .so .so.1 .so.%%VERSION%%
	${ECHO_CMD} lib/libXclasses${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} share/Xclasses/Xclasses >> ${PLIST}
.for ii in share include
	${ECHO_CMD} @dirrm ${ii}/Xclasses >> ${PLIST}
.endfor

do-install:
	@cd ${WRKSRC} && ${SH} build install
	@${INSTALL_SCRIPT} ${WRKSRC}/setenvxc ${PREFIX}/bin

.include <bsd.port.mk>
