# New ports collection makefile for:	aewm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	aewm
PORTVERSION=	1.2.7
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.red-bean.com/decklin/aewm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICCCM-compliant window manager based on 9wm

USE_XORG=	x11 xext xt xaw
WANT_GNOME=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" XROOT="${LOCALBASE}"

MAN1=		aeclients.1 aewm.1

GTKCLIENTS=	aemenu-gtk aepanel-gtk
XAWCLIENTS=	aemenu-xaw aepanel-xaw aesession set-gnome-pda

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk
.else
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
MAKE_ENV+=	DEFINES="-DXFT" \
		EXTRA_INC="`pkg-config --cflags xft`" \
		EXTRA_LIBS="`pkg-config --libs xft`"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIR/s|clients||g' ${WRKSRC}/Makefile
.for i in clients/lib/aeclients.h src/aewm.h
	@${REINPLACE_CMD} -e 's|/etc/X11/|${PREFIX}/etc/|g' ${WRKSRC}/${i}
.endfor

post-build:
.if ${HAVE_GNOME:Mgtk20}!=""
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
.if ${HAVE_GNOME:Mgtk20}!=""
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
.for i in DESIGN LICENSE NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
