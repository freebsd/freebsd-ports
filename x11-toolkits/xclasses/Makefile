# New ports collection makefile for:	xclasses
# Date created:		2000-10-01
# Whom:			trevor
#
# $FreeBSD$
#

PORTNAME=	xclasses
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/xcmail/Xclasses%20lib/${PORTVERSION}
DISTNAME=	Xclasses-public-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ layout library for X

DEPRECATED=		Version branch long since retired
EXPIRATION_DATE=	2007-10-28

USE_LDCONFIG=	yes
NOT_FOR_ARCHS=	alpha amd64 ia64 sparc64
PLIST=		${WRKDIR}/pkg-plist
PLIST_SUB=	VERSION="${PORTVERSION}"
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_XORG=	x11 xpm
WRKSRC=		${WRKDIR}/xclasses

pre-configure:
.for file in build System/ARules.FreeBSD
	@${PERL} -pi \
		-e "s|%%CXX%%|${CXX}|g;" \
		-e "s|%%CXXFLAGS%%|${CXXFLAGS}|g;" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g;" ${WRKSRC}/${file}
.endfor
	${REINPLACE_CMD} -e 's|\([:alnum:]\)\\$$|\1 \\|' ${WRKSRC}/Makefile

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
