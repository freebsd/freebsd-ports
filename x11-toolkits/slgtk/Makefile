# New ports collection makefile for:	slgtk
# Date created:		28 May 2008
# Whom:			Alexey Shuvaev <shuvaev@phyisik.uni-wuerzburg.de>
#
# $FreeBSD$
#

PORTNAME=	slgtk
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://space.mit.edu/pub/cxc/modules/slgtk/

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	S-Lang binding for GTK+

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LDFLAGS=-lncurses

MAN1=		imdisplay.1

OPTIONS=	FITS "Install gdk-pixbuf FITS image loader" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-ccdebug SLGTK_DEVEL_BUILD=true
.endif

.if !defined(WITHOUT_FITS)
ALL_TARGET=	dynamic pixbuf_loader
INSTALL_TARGET=	install install_pixbuf_loader
PLIST_SUB+=	FITS=""
.else
ALL_TARGET=	dynamic
PLIST_SUB+=	FITS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\.\.|${EXAMPLESDIR}| ; s|"examples"|"."|' \
		${WRKSRC}/examples/main.sl
	@${REINPLACE_CMD} -e '/rm -f devel/d ; /ln -sf @prefix@ devel/d' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/text/slgtk.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/images
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.sl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/packages/wdisplay.sl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/images/gtk-logo-rgb.gif ${EXAMPLESDIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/test.xpm ${EXAMPLESDIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/stars.fits ${EXAMPLESDIR}/images
.endif

.include <bsd.port.post.mk>
