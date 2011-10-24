# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	enlightenment
PORTVERSION=	0.16.999.55225
PORTEPOCH=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://download.enlightenment.org/snapshots/2010-12-03/ \
		http://files.roorback.net/e17/2010-12-03/base/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very artistic X window manager

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

LICENSE=	BSD
DIST_SUBDIR=    e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina eet evas ecore edbus efreet edje libtool_hack librt_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_EVAS_ENGINES=	buffer
USE_EFL_ECORE=	ipc
USE_GNOME=	gnomehack pkgconfig
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-profile=MEDIUM_PC \
		--disable-bluez

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|linkexec_info|link_execinfo|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\(setuid_root_mode = a=rx,u+x\)s|\1|g' ${WRKSRC}/src/bin/Makefile.in ${WRKSRC}/src/modules/cpufreq/Makefile.in

post-install:
	@${ECHO_MSG} '********************************************************'
	@${ECHO_MSG} 'NOTE: If you want "Shutdown" and "Restart"'
	@${ECHO_MSG} 'menu actions to work properly, manually set SUID bit on'
	@${ECHO_MSG} '"${PREFIX}/lib/enlightenment/utils/enlightenment_sys"'
	@${ECHO_MSG} 'executable.'
	@${ECHO_MSG}
	@${ECHO_MSG} 'WARNING: this program might be vulnerable so do not'
	@${ECHO_MSG} 'set suid bit if do not trust all users of this machine.'
	@${ECHO_MSG} '********************************************************'

.include <bsd.port.mk>
