# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.5
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/enlightenment/ \
		ftp://ftp.enlighte.nu/pub/Enlightenment/Enlightenment/ \
		ftp://beaver.its.vu.edu.au/pub/enlightenment/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Marble.etheme \
		BlueSteel.etheme.zh_TW.Big5 \
		BrushedMetal-Tigert.etheme.zh_TW.Big5 \
		ShinyMetal.etheme.zh_TW.Big5
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	Fnlib.0:${PORTSDIR}/graphics/fnlib \
		ghttp.1:${PORTSDIR}/www/libghttp \
		intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_ESOUND=	yes
USE_IMLIB=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsstd --with-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

.include <bsd.port.pre.mk>

.if (${MACHINE} == "alpha") && (${XFREE86_VERSION} == 3)
CONFIGURE_ARGS+=--disable-zoom
.endif

MAN1=		enlightenment.1

pre-build:
.for i in Marble.etheme BlueSteel.etheme.zh_TW.Big5 BrushedMetal-Tigert.etheme.zh_TW.Big5 ShinyMetal.etheme.zh_TW.Big5
	${CP} ${DISTDIR}/$i ${WRKSRC}/src/themes
.endfor

post-install:
	${RM} ${PREFIX}/share/enlightenment/themes/Ganymede/dialogs/#dialogs.cfg#
	${CHOWN} -R root:wheel ${PREFIX}/share/enlightenment/themes
	${CHMOD} -R a+rX ${PREFIX}/share/enlightenment/themes

.include <bsd.port.post.mk>
