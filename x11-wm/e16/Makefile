# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.6
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:enlightenment/} \
		ftp://freebsd.sinica.edu.tw/pub/clive/:ethemes
MASTER_SITE_SUBDIR=	${PORTNAME}/:enlightenment
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:enlightenment \
		Marble.etheme:ethemes \
		BlueSteel.etheme.zh_TW.Big5:ethemes \
		BrushedMetal-Tigert.etheme.zh_TW.Big5:ethemes \
		ShinyMetal.etheme.zh_TW.Big5:ethemes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A very artistic X window manager

LIB_DEPENDS=	Fnlib.0:${PORTSDIR}/graphics/fnlib \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	esound imlib
USE_FREETYPE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --disable-hints-gnome --disable-hints-kde
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		enlightenment.1

.include <bsd.port.pre.mk>

.if (${MACHINE} == "alpha") && (${XFREE86_VERSION} == 3)
CONFIGURE_ARGS+=	--disable-zoom
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wctype.h||g ; \
		 s|-ldl||g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DATADIR}/themes/Marble
	${TAR} -C ${DATADIR}/themes/Marble \
		-xzf ${DISTDIR}/Marble.etheme
	${TAR} -C ${DATADIR}/themes/BlueSteel \
		-xzf ${DISTDIR}/BlueSteel.etheme.zh_TW.Big5
	${TAR} -C ${DATADIR}/themes/BrushedMetal-Tigert \
		-xzf ${DISTDIR}/BrushedMetal-Tigert.etheme.zh_TW.Big5
	${TAR} -C ${DATADIR}/themes/ShinyMetal \
		-xzf ${DISTDIR}/ShinyMetal.etheme.zh_TW.Big5
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/themes
	${CHMOD} -R a+rX ${DATADIR}/themes

.include <bsd.port.post.mk>
