# Created by: trevor
# $FreeBSD$

PORTNAME=	aewm
PORTVERSION=	1.2.7
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.red-bean.com/decklin/aewm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICCCM-compliant window manager based on 9wm

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" XROOT="${LOCALBASE}"
USE_XORG=	x11 xext xt xaw
WANT_GNOME=	yes

MAN1=		aeclients.1 aewm.1
# XXX should use LICENSE instead of installing it as part of documentation,
# but our license framework does not support XFree86 license at this moment
PORTDOCS=	DESIGN LICENSE NEWS README TODO

GTKCLIENTS=	aemenu-gtk aepanel-gtk
XAWCLIENTS=	aemenu-xaw aepanel-xaw aesession set-gnome-pda

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20} != ""
USE_GNOME=	gtk20
PLIST_FILES=	bin/aemenu-gtk bin/aepanel-gtk
.endif

.if defined(WITH_XFT)
XORG+=		xft
MAKE_ENV+=	DEFINES="-DXFT" \
		EXTRA_INC="`pkg-config --cflags xft`" \
		EXTRA_LIBS="`pkg-config --libs xft`"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIR/s| clients||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/X11|${PREFIX}/etc|' \
		${WRKSRC}/clients/lib/aeclients.h ${WRKSRC}/src/aewm.h

post-build:
.if ${HAVE_GNOME:Mgtk20} != ""
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${GTKCLIENTS} ${XAWCLIENTS}
.else
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${XAWCLIENTS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aewm ${PREFIX}/bin
.for i in ${XAWCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${PREFIX}/bin
.endfor
.if ${HAVE_GNOME:Mgtk20} != ""
.for i in ${GTKCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${PREFIX}/bin
.endfor
	${LN} -sf aemenu-gtk ${PREFIX}/bin/aemenu
	${LN} -sf aepanel-gtk ${PREFIX}/bin/aepanel
.else
	${LN} -sf aemenu-xaw ${PREFIX}/bin/aemenu
	${LN} -sf aepanel-xaw ${PREFIX}/bin/aepanel
.endif
	${INSTALL_MAN} ${WRKSRC}/src/aewm.1x ${MANPREFIX}/man/man1/aewm.1
	${INSTALL_MAN} ${WRKSRC}/clients/aeclients.1x \
		${MANPREFIX}/man/man1/aeclients.1
	@${MKDIR} ${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/src/aewmrc.sample ${PREFIX}/etc/aewm
	${INSTALL_DATA} ${WRKSRC}/clients/clientsrc.sample ${PREFIX}/etc/aewm
.if !exists(${PREFIX}/etc/aewm/aewmrc)
	cd ${PREFIX}/etc/aewm && ${CP} aewmrc.sample aewmrc
.endif
.if !exists(${PREFIX}/etc/aewm/clientsrc)
	cd ${PREFIX}/etc/aewm && ${CP} clientsrc.sample clientsrc
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
