# New ports collection makefile for:	aewm
# Date created:				2000-12-16
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	aewm
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.red-bean.com/~decklin/aewm/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	ICCCM-compliant window manager based on 9wm

GTKCLIENTS=	aemenu-gtk aepanel-gtk
XAWCLIENTS=	set-gnome-pda \
		aesession \
		aemenu-xaw \
		aepanel-xaw
DOCDIR=		share/doc/${PORTNAME}
DOCS=		ChangeLog README TODO DESIGN LICENSE
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" XROOT="${X11BASE}"
MAN1=		aewm.1 aeclients.1
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i '' -E

.include <bsd.port.pre.mk>
.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PKGNAMESUFFIX=	-gtk
.endif

do-patch:
	${REINPLACE_CMD} 's:/etc/X11/aewm/aewmrc:${PREFIX}/etc/aewmrc:g' \
		${WRKSRC}/src/aewm.h
	${REINPLACE_CMD} 's:clients::g' ${WRKSRC}/Makefile
.if ${HAVE_GNOME:Mgtk20}!=""
	${REINPLACE_CMD} 's:gtk-config:${GTK_CONFIG}:g' \
		${WRKSRC}/clients/Makefile
	${REINPLACE_CMD} 's:/etc/X11/aewm/clientsrc:${PREFIX}/etc/clientsrc:g' \
		${WRKSRC}/clients/lib/aeclients.h
.endif

post-build:
.if ${HAVE_GNOME:Mgtk20}!=""
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${GTKCLIENTS} ${XAWCLIENTS}
.else
	cd ${WRKSRC}/clients && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} \
		${XAWCLIENTS}
.endif

pre-install:
	${RM} -f ${PLIST}
.for i in aewm aemenu aepanel ${XAWCLIENTS}
	${ECHO_CMD} bin/${i} >> ${PLIST}
.endfor
.if ${HAVE_GNOME:Mgtk20}!=""
.for i in ${GTKCLIENTS}
	${ECHO_CMD} bin/${i} >> ${PLIST}
.endfor
.endif
	${ECHO_CMD} share/examples/aewm/aewmrc.sample >> ${PLIST}
	${ECHO_CMD} share/examples/aewm/clientsrc.sample >> ${PLIST}
	${ECHO_CMD} etc/aewmrc >> ${PLIST}
	${ECHO_CMD} etc/clientsrc >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif
	${ECHO_CMD} @dirrm share/examples/aewm >> ${PLIST}

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/aewm ${PREFIX}/bin
.for i in ${XAWCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${PREFIX}/bin
.endfor
.if ${HAVE_GNOME:Mgtk20}!=""
.for i in ${GTKCLIENTS}
	${INSTALL_PROGRAM} ${WRKSRC}/clients/${i} ${PREFIX}/bin
.endfor
	cd ${PREFIX}/bin && ${LN} -s aemenu-gtk aemenu && \
		${LN} -s aepanel-gtk aepanel
.else
	cd ${PREFIX}/bin && ${LN} -s aemenu-xaw aemenu && \
		${LN} -s aepanel-xaw aepanel
.endif
	${INSTALL_DATA} ${WRKSRC}/clients/clientsrc.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/aewmrc.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/aewmrc.sample ${PREFIX}/etc/aewmrc
	${INSTALL_DATA} ${WRKSRC}/clients/clientsrc.sample \
		${PREFIX}/etc/clientsrc
	${INSTALL_MAN} ${WRKSRC}/src/aewm.1x ${MANPREFIX}/man/man1/aewm.1
	${INSTALL_MAN} ${WRKSRC}/clients/aeclients.1x \
		${MANPREFIX}/man/man1/aeclients.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
