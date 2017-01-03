# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightdm
PORTVERSION=	1.20.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Lightweight Display Manager

# library/bindings are LGPLv2 or LGPLv3, the rest GPLv3+
LICENSE=	LGPL20 LGPL3 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LGPL2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPL3

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libck-connector.so:sysutils/consolekit \
		libgcrypt.so:security/libgcrypt \
		libxklavier.so:x11/libxklavier

USES=		localbase gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intlhack
USE_XORG=	x11 xcb xdmcp
CONFIGURE_ARGS=	--disable-tests # PAM errors
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	lightdm
SUB_FILES=	Xsession

USERS=		lightdm
GROUPS=		lightdm

OPTIONS_DEFINE=	DOCS VALA
OPTIONS_DEFAULT=VALA
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc

VALA_BUILD_DEPENDS=	vapigen:lang/vala
VALA_CONFIGURE_ENABLE=	vala
VALA_USE=		gnome=introspection:build

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/data/lightdm.conf

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc/init
	${INSTALL_SCRIPT} ${WRKDIR}/Xsession ${STAGEDIR}${PREFIX}/etc/lightdm/
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/keys.conf ${STAGEDIR}${PREFIX}/etc/lightdm/keys.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/lightdm.conf ${STAGEDIR}${PREFIX}/etc/lightdm/lightdm.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/users.conf ${STAGEDIR}${PREFIX}/etc/lightdm/users.conf.sample
	${MKDIR} ${STAGEDIR}/var/cache/lightdm \
		${STAGEDIR}/var/log/lightdm \
		${STAGEDIR}/var/run/lightdm
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xgreeters
	@(cd ${STAGEDIR}${PREFIX}/share/xgreeters && \
		${LN} -sf lightdm-gtk-greeter.desktop default.desktop)

.include <bsd.port.mk>
